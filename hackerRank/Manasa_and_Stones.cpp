#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int t;
	long int n,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		if(a==b)
			cout<<a*(n-1);
		else
		{
			set<long int> last_no;
			for(long int i=0;i<n;i++)
				last_no.insert((a*(n-1-i))+(b*i));
			set<long int>::iterator it;
			for(it=last_no.begin();it!=last_no.end();++it)
				cout<<*it<<' ';
		}
		cout<<'\n';
	}
}
