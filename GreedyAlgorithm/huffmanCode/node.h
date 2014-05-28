
#include <iostream>
using namespace std;

struct Node
{
	int freq;
	char ch;
	string code;
	Node *left;
	Node *right;
	Node(int x, char y, Node *l = NULL, Node *r = NULL)
		:freq(x),ch(y),left(l),right(r){code = "";}
	Node(int x, Node *l = NULL, Node *r = NULL){
		freq = x;
		ch = '#';
		code = "";
		left = l;
		right = r;
	}
	/*
	bool operator <(const Node *x) const
	{
		return x->freq < value;
	}
	*/
};

struct cmp
{
	bool operator () (Node *a, Node *b)
	{
		return a->freq > b->freq;
	}
};
	
