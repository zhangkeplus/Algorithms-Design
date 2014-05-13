#include <iostream>
#include <math.h>
using namespace std;
int s1[10000] = {0};
int s2[10000] = {0};

int getMinimum(int x)
{
	int count = 0;
	int r = x;
	while( x%2 == 0 )
	{
		x = x/2;
		count++;
	}
	return r- pow(2.0,count) + 1; 
}

int getMaximum(int x)
{
	int count = 0;
	int r = x;
	while( x%2 == 0 )
	{
		x = x/2;
		count++;
	}
	return r + pow(2.0,count) - 1;
}

int main()
{
	int N,t;
	cin>>N;
	int c = N;
	int i = 0, j = 0;
	while(c--)
	{
		cin>>t;
		s1[i++] = getMinimum(t);
		s2[j++] = getMaximum(t);
	}
	for(int k = 0; k < N; k++ )
	{
		cout<<s1[k]<<' '<<s2[k]<<endl;
	}
}
