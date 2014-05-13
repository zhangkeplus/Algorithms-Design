#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int count = 0;
struct BSTNode
{
	string species;
	int num;
	BSTNode *left, *right;
	BSTNode():left(NULL), right(NULL){}
	BSTNode(string x, int n = 0, BSTNode *l = NULL, BSTNode *r = NULL)
		:species(x), num(n), left(l), right(r){}
};

class Tree
{
	public:
		Tree():root(NULL){}
		void insert(Tree &t, BSTNode *z);
		void inorder(BSTNode *p);
		BSTNode *getRoot(Tree t);
	private:
		BSTNode *root;
};

BSTNode *Tree::getRoot(Tree t)
{
	return t.root;
}

void Tree::insert(Tree &t, BSTNode *z)
{
	BSTNode *y = NULL;
	BSTNode *x = t.root;
	while( x != NULL )
	{
		y = x;
		if ( z->species == x->species )
		{
			x->num++;
			break;
		}
		else if ( z->species < x->species )
		{
			x = x->left;
		}
		else
			x = x->right;
	}
	if ( y == NULL )
	{
		t.root = z;
		z->num++;
	}
	else if ( x == NULL)
	{
		if ( z->species < y->species )
			y->left = z;
		else
			y->right = z;
		z->num++;
	}
}

void Tree::inorder(BSTNode *p)
{
	if ( p != NULL)
	{
		inorder(p->left);
		double percent =double( (p->num)*100)/(count);
		cout << p->species<<" "<<fixed<< setprecision(4)<<percent <<endl;
		inorder(p->right);
	}
}

int main()
{
	freopen("1.txt","r",stdin);
	string s;
	Tree t;
	while (getline(cin,s))
	{
		BSTNode *newNode = new BSTNode(s); 
		count++;
	 	//cout<<s<<endl;
		t.insert(t,newNode);
	}
	BSTNode *x = t.getRoot(t);
	t.inorder(x);
	return 0;
}
