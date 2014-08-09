#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int t;
	int i,j;
	int convert_nos;
	cin>>t;
	while(t--)
	{
		char str[10000];
		cin>>str;
		i=0,j=strlen(str)-1;
		convert_nos=0;
		while(i<j)
		{
			convert_nos+=abs(str[i]-str[j]);
			i++;
			j--;
		}
		cout<<convert_nos<<'\n';
	}
	return 0;
}

