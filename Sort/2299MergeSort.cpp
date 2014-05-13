#include <iostream>
#define MAXLEN 500005
#define MAXINTEGER 1000000000
using namespace std;

int L[MAXLEN]={0},R[MAXLEN]={0},s[MAXLEN]={0};
long long  count;

void merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	for(int i = 0; i < n1; i++)
		L[i] = A[p+i];
	for(int j = 0; j < n2; j++)
		R[j] = A[q + j +1];
	L[n1] = MAXINTEGER;
	R[n2] = MAXINTEGER;
	int i = 0, j = 0;
	for(int k = p; k <= r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
			count += n1 - i;
		}
	}
}

void mergeSort(int A[], int p, int r)
{
	if ( p < r )
	{
		int q = ( p + r ) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	int n;
	cin>>n;
	while( n!=0)
	{
		count = 0;
		for(int i = 0; i < n; i++)
			cin>>s[i];
		mergeSort(s,0,n-1);
		cout<<"minimum number of swap: "<<count<<endl;
		cin>>n;
	}
	return 0;
}
