/*************************************************************************
	> File Name: matrixChainMulti.cpp
	> Author: zhangke
	> Mail: zhangkeplus@gmail.com 
	> Created Time: Fri 16 May 2014 12:13:01 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;
#define MAXINT 1000000

ifstream fin("test.txt");
int num;
int p[100];
int m[100][100],s[100][100];

void input()
{
    cout << "Input the number of matrix : ";
    fin >> num;
    cout << "Input the row and column of each matrix : ";
    for ( int i = 0; i <= num; i++ ){
        fin >> p[i];
    }
}

void dp(int p[], int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for ( int l = 2; l <= n; l++ ){
        for ( int i = 1; i <= n-l+1; i++ ){
            int j = i + l - 1;
            int q = MAXINT;
            for ( int k = i; k < j; k++ ){
                if ( q > m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j] ){
                    q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printParens(int s[][100], int i, int j)
{
    if ( i == j ){
        cout << "A"<< i;
    }
    else{
        cout << "(";
        printParens(s,i,s[i][j]);
        printParens(s,s[i][j]+1,j);
        cout << ")";
    }
}

// print split position of Ai*...*Aj
void printSplit(int s[][100])
{
    cout << endl;
    for( int i = 1; i <= num; i++ ){
        for( int j = 1; j <=num; j++ ){
            cout <<"s["<<i<<"]["<<j<<"] is "<<s[i][j]<<endl;
        }
    }

}

void printCost(int m[][100])
{
    cout << endl;
    for( int i = 1; i <= num; i++ ){
        for( int j = 1; j <=num; j++ ){
            cout <<"m["<<i<<"]["<<j<<"] is "<<m[i][j]<<endl;
        }
    }
}

int main()
{
    input();
    dp(p,num);
    printCost(m);
    printSplit(s);
    printParens(s,1,num);
}
