#include<iostream>
using namespace std;
int main()
{
	int t;
	long int n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n&1)
		{
			if(k==(n>>1))
				cout<<2*k;
			else if(k<(n>>1))
				cout<<2*k+1;
			else
				cout<<n-(k-(n>>1))*2-1;
		}
		else
		{	
			if(k<=((n-1)>>1))
				cout<<2*k+1;
			else
				cout<<n-(k-((n-1)>>1))*2;
		}
		cout<<'\n';
	}
}
