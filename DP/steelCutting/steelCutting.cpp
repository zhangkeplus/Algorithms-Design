/*************************************************************************
	> File Name: steelCutting.cpp
	> Author: zhangke
	> Mail: zhangkeplus@gmail.com 
	> Created Time: Thu 15 May 2014 12:50:37 PM CST
 ************************************************************************/
#include<iostream>
#include<fstream>
using namespace std;

int r[100],p[100],s[100];

void dp(int p[], int n)
{
    r[0] = 0;
    for (int j = 1; j <= n; j++){
        int q = -1;
        for (int i = 1; i <= j; i++){
            if ( q < p[i] + r[j-i])
            {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void print(int p[], int n)
{
    while ( n > 0 )
    {
        printf("%d ",s[n]);
        n = n - s[n];
    }
}

int main()
{
    ifstream fin("input.txt");
    int N;
    fin >> N;
    for (int i = 1; i <= N; i++){
        fin >> p[i];
    }
    dp(p,N);
   /* for (int i = 1; i <= N; i++){
        cout << r[i]<<' ';
    }
    */
    print(p,N);
}
