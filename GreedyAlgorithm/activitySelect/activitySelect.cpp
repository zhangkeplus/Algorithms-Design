#include <iostream>
#include <fstream>
#define MAX_SCALE 1000
using namespace std;

int n;
//递归贪心算法
void recursiveActivitySelect(int s[], int f[], int k, int n )
{
	int m = k + 1;
	while(m <= n && s[m] < f[k]) {
		m++;
	}
	if (m <= n)
	{
		cout<<m<<endl;
		recursiveActivitySelect(s,f,m,n);
	}
	else
		return;
}
//迭代贪心算法
void activitySelect(int s[], int f[], int n)
{
	cout<<1;
	int k=1;
	for(int m = 2; m <= n; m++){
		if(s[m] >= f[k]){
			cout<<m;
			k=m;
		}
	}
}
void input(int s[], int f[])
{
	fstream fin("test");
	s[0]=0;
	f[0]=0;
	fin>>n;
	for(int i = 1; i <= n; i++){
		fin>>s[i];
	}
	for (int i = 1; i <= n; i++){
		fin>>f[i];
	}
}

int main() 
{
	int s[MAX_SCALE],f[MAX_SCALE];
	input(s,f);
	//recursiveActivitySelect(s,f,0,n);
	activitySelect(s,f,n);
}
