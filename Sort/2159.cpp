#include <iostream>
#include <cstring>
using namespace std;

int partition(int  str[], int p, int r)
{
	int x = str[r];
	int i = p-1;
	for(int j=p; j<=r-1;j++)
	{
		if(str[j]<=x)
		{
			i++;
		 	int temp = str[i];
			str[i]=str[j];
			str[j]=temp;
		}
	}
	int temp = str[i+1];
	str[i+1] = str[r];
	str[r] = temp;
	return i+1;
}

void quicksort(int str[], int p , int r)
{
	if (p<r)
	{
		int	q = partition(str,p,r);
		quicksort(str,p,q-1);
		quicksort(str,q+1,r);
	}
}

bool judge(int x[26], int y[26])
{
	for(int i=0;i<26;i++)
		if(x[i] != y[i])
			return false;
	return true;
}

int main()
{
	char a[100],b[100];
	cin>>a>>b;
	int	len = strlen(b);
        if (len!=strlen(a))
              cout<<"NO";
        else
        {
	   int s1[26],s2[26];
           for(int i=0;i<26;i++)
           {
                s1[i]=0;s2[i]=0;
           }
           for(int i=0;i<len;i++)
	   {
	       	s1[a[i]-'A']++;
		s2[b[i]-'A']++;
	   }
	   quicksort(s1,0,25);
	   quicksort(s2,0,25);

	   if (judge(s1,s2))
		cout<<"YES";
	   else
		cout<<"NO";
        }
	return 0;
}
