#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main()
{
	BST<int> btree;
	int a[10] = {5,2,4,8,1,6,7,10,3,9};
	for(int i = 0; i< 10; i++)
	{
		BSTNode<int> *temp = new BSTNode<int>(a[i]);
		btree.insert(btree,temp);
	}
	btree.preorder(btree.root);
	cout<<endl<<"chose the number you want to delete : ";
	int chose;
	cin>>chose;
	BSTNode<int> *d = btree.search(btree.root,chose);
	btree.destroy(btree,d);
	btree.preorder(btree.root);
}
