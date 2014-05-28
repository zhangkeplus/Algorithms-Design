/*    
 *  Theorem : (Optimal substructure of an LCS)
 *  Let \( X = \) and Y=<y1,y2,…,yn> be sequences, and let \( Z = \) be any LCS of X and Y.
 *      If xm=yn, then zk=xm=yn and Zk−1 is an LCS of Xm−1 and Yn−1.
 *      If xm≠yn, then zk≠xm impliesthat\(Z is an LCS of Xm−1 and Y.
 *      If xm≠yn, then zk≠yn implies that Z is an LCS of X and Yn−1.
 *
 */

#include <iostream>
#include <fstream>
#include <string.h>
#define MAX 1000
using namespace	std;

int c[MAX][MAX]; 
int m,n;
string X,Y; 
void LCS(string X, string Y)
{
	m = X.length();
	n = Y.length();
	for(int i = 1; i <= m; i++)
		c[i][0] = 0;
	for(int j = 1; j <= n; j++)
		c[0][j] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++){
			if(X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if (c[i-1][j] >= c[i][j-1])
				c[i][j] = c[i-1][j];
			else
				c[i][j] = c[i][j-1];
		}
}

void printLCS(string X, int i, int j)
{
	if(i == 0 || j == 0)
		return;
	if(c[i][j] == c[i-1][j-1]+1){
		printLCS(X,i-1,j-1);
		cout<<X[i-1]<<endl;
	}
	else if(c[i][j] == c[i-1][j]){
		printLCS(X,i-1,j);
	}
	else
		printLCS(X,i,j-1);

//	else if(c[i][j] == c[i][j-1]){
//		printLCS(X,i,j-1);
//	}
//	else
//		printLCS(X,i-1,j);

}
// output the Length of LCS ,c[i][j]
void printLength()
{
	for(int i = 1; i <= m; i++) 
		for(int j = 1; j <= n; j++)
			cout<<"c["<<i<<"]["<<j<<"] : "<<c[i][j]<<endl;
}
void input(){
	fstream fin("test.txt");
	fin>>X>>Y;
}
int main()
{
	input();
	LCS(X,Y);
	printLCS(X,m,n);
	//printLength();
	return 0;
}
