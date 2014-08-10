#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int rock_comp[n][26];
	for(int i=0;i<n;i++)
		for(int j=0;j<26;j++)
			rock_comp[i][j]=0;
	for(int i=0;i<n;i++)
	{
		char comp[100];
		cin>>comp;
		for(int j=0;j<strlen(comp);j++)
			rock_comp[i][comp[j]-97]=1;
	}
	int count=0;
	int flag;
	for(int i=0;i<26;i++)
	{
		flag=1;
		for(int j=0;j<n;j++)
		{
			if(!rock_comp[j][i])
			{
				flag=0;
				break;
			}
		}
		if(flag) count++;
	}
	cout<<count<<endl;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			cout<<rock_comp[i][j];
		}
		cout<<endl;
	}*/
	return 0;
}
