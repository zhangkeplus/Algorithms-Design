/*
 * head file
 */
#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
	T data;
	BSTNode<T> *left, *right, *parent;
	BSTNode():left(NULL), right(NULL), parent(NULL){}
	BSTNode(T x, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL, BSTNode<T> *p = NULL)
		:data(x), left(l), right(r), parent(p){}
};

template <class T>
class BST
{
	public:
		BST():root(NULL){}
		BSTNode<T> *search(BSTNode<T> *x, T k);
		BSTNode<T> *getMinimum(BSTNode<T> *x);
		BSTNode<T> *getMaximum(BSTNode<T> *x);
		BSTNode<T> *getSuccessor(BSTNode<T> *x);
		void insert(BST<T> &tree, BSTNode<T> *z);
		void transplant(BST<T> &tree, BSTNode<T> *u, BSTNode<T> *v);
		void destroy(BST<T> &tree, BSTNode<T> *z);
		void preorder(BSTNode<T> *p);
		BSTNode<T> *root;
};

template <class T>
BSTNode<T> *BST<T>::search(BSTNode<T> *x, T k)
{
	if ( x == NULL || k == x->data )
		return x;
	if ( k < x->data )
		return search(x->left,k);
	else
		return search(x->right,k);
};

template <class T>
BSTNode<T> *BST<T>::getMinimum(BSTNode<T> *x)
{
	while ( x->left != NULL)
		x = x->left;
	return x;
};

template <class T>
BSTNode<T> *BST<T>::getMaximum(BSTNode<T> *x)
{
	while ( x->right != NULL )
		x = x->right;
	return x;
};

template <class T>
BSTNode<T> *BST<T>::getSuccessor(BSTNode<T> *x)
{
	if ( x->right != NULL)
		return getMinimum(x->right);
	BSTNode<T> *y;
	y = x->parent;
	while ( y != NULL && x == y->right )
	{
		x = y;
		y = y->parent;
	}
	return y;
};

template <class T>
void BST<T>::insert(BST<T> &tree, BSTNode<T> *z)
{
	BSTNode<T> *y = NULL;
	BSTNode<T> *x = tree.root;
	while ( x != NULL )
	{
		y = x;
		if ( z->data < x->data )
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if ( y == NULL )
		tree.root = z;
	else if ( z->data < y->data )
		y->left = z;
	else
		y->right = z;
};

template <class T>
void BST<T>::transplant(BST<T> &tree, BSTNode<T> *u, BSTNode<T> *v)
{
	if ( u->parent == NULL )
		tree.root = v;
	else if ( u == u->parent->left )
		u->parent->left = v;
	else
		u->parent->right = v;
	if ( v != NULL )
		v->parent = u->parent;
};

template <class T>
void BST<T>::destroy(BST<T> &tree, BSTNode<T> *z)
{
	if ( z->left == NULL )
		transplant(tree, z, z->right);
	else if ( z->right == NULL )
		transplant(tree, z, z->left);
	else
	{
		BSTNode<T> *y = getMinimum(z->right);
		if ( y->parent != z )
		{
			transplant(tree, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
};

template <class T>
void BST<T>::preorder(BSTNode<T> *p)
{
	if ( p != NULL )
	{
		cout << p->data;
		preorder(p->left);
		preorder(p->right);
	}

};
