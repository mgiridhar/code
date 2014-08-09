#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long int n,t;
	cin>>n>>t;
	long int width[n];
	long int i,j;
	int l,m,k;
	for(i=0;i<n;i++)
		cin>>width[i];
	for(i=0;i<t;i++)
	{
		cin>>l>>m;
		k=3;
		for(j=l;j<=m;j++)
		{
			if(width[j]<k)
				k=width[j];	
		}
		cout<<k<<'\n';
	}
 	return 0;
}
