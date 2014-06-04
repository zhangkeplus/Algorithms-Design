#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define MAX 1000
using namespace std;

int N;
int e[MAX][MAX];
struct Node{
	int color;
	int dis;
	int index;
	int parent;
};

void input(){
	fstream fin("test");
	fin >> N;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			fin >> e[i][j];
}

vector<int> edge[MAX];
void matrixToList()
{
	for(int i = 1; i <= N; i++)
		edge[i].clear();
	for(int i = 1; i <=N; i++){
		for(int j = 1; j <= N; j++)
		{
			if(e[i][j] != 0){
				edge[i].push_back(j);
			}
		}
	}
}

Node vertex[MAX];
void initVertex()
{
	for(int i = 1; i <= N; i++){
		vertex[i].color = -1;
		vertex[i].dis = -1;
		vertex[i].index = i;
		vertex[i].parent = -1;
	}
}
void bfs(int start)
{
	queue<Node> Q;

	vertex[start].color = 1;
	vertex[start].dis = 0;
	vertex[start].parent = -1;

	while(!Q.empty())
		Q.pop();
	Q.push(vertex[start]);
	while(!Q.empty())
	{
		Node tmp;
		tmp = Q.front();
		Q.pop();
		int i = tmp.index;
		for(int j = 0; j < edge[i].size(); j++){
			int t = edge[i][j];
			if(vertex[t].color == -1){
				vertex[t].color = 1;
				vertex[t].dis = vertex[i].dis + 1;
				vertex[t].index = t;
				vertex[t].parent = i;
				Q.push(vertex[t]); 
			}
		}
		vertex[i].color = 1;
	}

}

void printPath(int s, int v)
{
	if(v == s)
		cout << s << endl;
	else if(vertex[v].parent == -1)
		cout << "no path from s to v exits" << endl;
	else
	{
		printPath(s,vertex[v].parent);
		cout << v <<endl;
	}
}

void printDis()
{
	for(int i = 1; i <= N; i++)
		cout<<vertex[i].dis<<' '<<vertex[i].color<<' '<<vertex[i].parent<<' '<<vertex[i].index<<endl;
}
int main()
{
	input();
	matrixToList();
	initVertex();
	bfs(1);
	//printPath(1,6);
	printDis();
}
