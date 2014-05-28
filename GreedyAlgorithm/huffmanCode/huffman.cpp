#include "node.h"
#include <iostream>
#include <fstream>
#include <queue>
#define MAX 1000
using namespace std;

int n;
int c[MAX];

void input()
{
	fstream fin("test");
	fin >> n;
	cout<<endl<<endl<<"The scale is : "<<n<<endl;
	cout<<"The input data : ";
	char ch='a';
	for(int i = 0; i < n; i++){
		fin>>c[i];
		char ch1 = ch + i;
		cout<<ch1<<":"<<c[i]<<' ';
	}
	cout<<endl<<endl;
}

Node* huffman()
{
	priority_queue< Node*, vector<Node*>, cmp > Q;//重点！！！！！
	char ch = 'a';
	for(int i = 0; i < n; i++){
		//将数据读入优先队列中
		char ch1 = ch + i;
		Node *temp = new Node(c[i],ch1);
		Q.push(temp);
	}

	//for(int i=0;i<n;i++){
	//	Node *x = Q.top();
	//	cout<<x->freq<<' ';
	//	Q.pop();
	//}

	for(int i = 1; i <= n-1; i++){
		//n-1次合并，之后huffman构造完成
		Node *x = Q.top();
		Q.pop();
		Node *y = Q.top();
		Q.pop();
		Node *z = new Node(x->freq+y->freq, x, y );
		Q.push(z);
		//cout<<x->freq<<' '<<x->ch<<' '<<y->freq<<' '<<y->ch<<' '<<z->freq<<' '<<z->ch<<endl;
	}

	Node *t = Q.top();
	return t;
}
void printHuffmanTree(Node *root)
{
	if(root != NULL){
		cout<<root->freq<<endl;
		printHuffmanTree(root->left);
		printHuffmanTree(root->right);
	}
}
void printHuffmanCode(Node *root)
{
	if(root->ch == '#') //内部结点
	{
		root->left->code = root->code + "0";
		root->right->code = root->code + "1";
		printHuffmanCode(root->left);
		printHuffmanCode(root->right);
	}
	else
	{
		cout<<root->ch<<" 's code : "<<root->code<<endl;
	}
}
int main()
{
	input();
	Node *root = huffman();
	//printHuffmanTree(root);
	printHuffmanCode(root);
	return 0;
}



