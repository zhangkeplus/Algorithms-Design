#include <iostream>
#include <fstream>
using namespace std;

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}

void quickSort(int A[], int p, int r)
{
	if( p < r)
	{
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	//ifstream("1.txt","r");
	int cow[10000];
	int N;
	cin>>N;
	for(int i = 0; i<N; i++)
		cin>>cow[i];
	quickSort(cow,0,N-1);
	int mid = N/2;
	cout<<cow[mid];
	return 0;
}
