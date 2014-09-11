#include<iostream>
using namespace std;
#define MOD 1000000007
int main()
{
	unsigned long int n,m,i,j;
	cin>>n>>m;
	unsigned long long int a[n+1],b[m+1],c[m+1],count[n+1];
	for(j=1;j<=n;j++)
		count[j]=-1;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(j=1;j<=m;j++)
		cin>>b[j];
	for(j=1;j<=m;j++)
		cin>>c[j];
	for(i=1;i<=m;i++)
	{
		if(count[b[i]]==-1)
			count[b[i]]=c[i];
		else
			count[b[i]]=(count[b[i]] * c[i]) % MOD;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;(j*i)<=n;j++)
		{
			if(count[i]!=-1)
				a[j*i] = (a[j*i] * count[i]) % MOD;
		}
	}
	for(i=1;i<=n;i++)
		cout<<a[i]<<' ';
}

