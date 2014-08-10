#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int k,temp;
	while(t--)
	{
		cin>>k;
		if(k&1)
		{
			temp = k>>1;
			cout<<(temp*(k-temp));
		}
		else
		{
			temp = k>>1;
			cout<<temp*temp;
		}
		cout<<endl;
	}
	return 0;
}
