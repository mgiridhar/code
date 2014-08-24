#include<iostream>
using namespace std;
int main()
{
	int t;
	unsigned long int n,no_5,no_3,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		no_3=no_5=0;
		if(n%3 == 0)
			no_5 = n;
		else
		{
			i=1;
			while(i<=n)
			{
				if( (n-i)%3==0 && i%5==0 )
				{
					no_3 = i;
					no_5 = n-i;
					break;
				}
				i++;
			}
		}
		if(no_3==0 && no_5==0)
			cout<<"-1";
		else
		{
			while(no_5--)
				cout<<'5';
			while(no_3--)
				cout<<'3';
		}
		cout<<'\n';
	}
}
