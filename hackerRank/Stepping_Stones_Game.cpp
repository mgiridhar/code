#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	unsigned long int t;
	unsigned long long int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		unsigned long long int i=(unsigned long long int)log(n);
		unsigned long long int sum = (i*(i+1))>>1;
		while(sum<n)
		{
			i++;
			sum += i;
		}
		if(sum==n)
			cout<<"Go On Bob "<<i;
		else
			cout<<"Better Luck Next Time";
		cout<<'\n';
	}
}
