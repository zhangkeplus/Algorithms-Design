/*
 * heap sort
 * A[1..HEAPSIZE]下标从1开始
 */
#include <iostream>
using namespace std;

typedef int E;
int HEAPSIZE;
int LEFT(int x){
	return 2*x;
}
int RIGHT(int x){
	return 2*x + 1;
}

void exchange(E &x, E &y)
{
	E temp;
    temp = x;
    x = y;
   	y = temp;
}

void maxHeapify(E A[],int i)
{
	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);
	if ( l <= HEAPSIZE && A[l] > A[i] )
		largest = l;
	else
		largest = i;
	if( r <= HEAPSIZE && A[r] > A[largest])
		largest = r;
	if ( largest != i )
	{
		exchange(A[i],A[largest]);
		maxHeapify(A,largest);
	}
}

void buildMaxHeap(E A[])
{
	for(int i = HEAPSIZE/2; i>=1; i--)
		maxHeapify(A,i);
}

void heapSort(E A[])
{
	buildMaxHeap(A);
	for(int i = HEAPSIZE; i >= 2; i--)
	{
		exchange(A[1],A[i]);
		HEAPSIZE--;
		maxHeapify(A,1);
	}
}

int main()
{
	int s[11] = {-1,4,1,3,2,16,9,10,14,8,7};
	HEAPSIZE = 10;
	heapSort(s);
	for(int i=1;i<=10;i++)
		cout<<s[i]<<' ';
}
