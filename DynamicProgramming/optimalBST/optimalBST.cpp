/*
 * 根据最优子结构，寻找最优解：
 *给定关键字ki,...,kj，假设kr(i<=r<=j)是包含这些键的一棵最优子树的根。其左子树
 *包含关键字ki,...,kr-1和虚拟键di-1,...,dr-1，右子树包含关键字kr+1,...,kj和虚拟键dr,...dj。
 *我们检查所有的候选根kr,就保证可以找到一棵最优二叉查找树。
 */

#include <iostream>
#include <fstream>
#define MAX 1000
#define MAXCOST 10000
using namespace std;

float p[MAX],q[MAX];
float e[MAX][MAX],w[MAX][MAX];
int root[MAX][MAX];
int n;

void optimalBST(float p[], float q[], int n)
{
	for(int i = 1; i <= n+1; i++)
	{
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for(int L = 1; L <= n; L++)
	{
		for(int i = 1; i <= n-L+1; i++)
		{
			int j = i+L-1;
			e[i][j] = MAXCOST;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for(int r = i; r <= j; r++)
			{
				float temp = e[i][r-1] + e[r+1][j] + w[i][j];
				if(temp < e[i][j]){
					e[i][j] = temp;
					root[i][j] = r;
				}
			}
		}
	}
}

void constructOptimalBST(int x, int y)
{
	if (x > y) 
		return;
	if(x == y){
		cout<<"q"<<x-1<<" is p"<<x<<" 's left child"<<endl;
		cout<<"q"<<x<<" is p"<<x<<" 's right child"<<endl;
		return;
	}

	int t = root[x][y];
	if(t == root[1][n]){
		cout<<"p"<<t<<" is root"<<endl;
	} 

	if(t==x){  //根节点是最左边的元素
		cout<<"q"<<x-1<<" is p"<<x<<" 's left child"<<endl;
		int tr = root[t+1][y]; //右子树的根
		cout<<"p"<<tr<<" is p"<<t<<" 's right child"<<endl;
		constructOptimalBST(t+1,y);
	}
	else if(t==y){ //根节点是最右边的元素
		int tl = root[x][t-1];
		cout<<"p"<<tl<<" is p"<<t<<" 's left child"<<endl;
		constructOptimalBST(x,t-1);
		cout<<"q"<<y<<" is p"<<y<<" 's right child"<<endl;
	}
	else{ //根节点在里面
		int tl = root[x][t-1]; //左子树的根
		int tr = root[t+1][y]; //右子树的根
		cout<<"p"<<tl<<" is p"<<t<<" 's left child"<<endl;
		constructOptimalBST(x,t-1);
		cout<<"p"<<tr<<" is p"<<t<<" 's right child"<<endl;
		constructOptimalBST(t+1,y);
	}
}
void input()
{
	fstream fin("test.txt");
	fin>>n; cout<<n<<' ';
	for(int i = 1; i <= n; i++){
		fin>>p[i];
		cout<<p[i]<<' ';
	}
	for(int i = 0; i <= n; i++){
		fin>>q[i];
		cout<<q[i]<<' ';
	}
	cout<<endl<<endl<<endl;
}
void outputRoot()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cout<<"root["<<i<<"]["<<j<<"] is "<<root[i][j]<<endl;
}
int main()
{
	input();
	optimalBST(p,q,n);
	outputRoot();
	constructOptimalBST(1,n);
	return 0;
}
