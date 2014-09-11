#include<iostream>
#include<cmath>
using namespace std;

bool is_perfect_sq(long double n)
{
	if(fmod(sqrt(n),1) == 0) return true;
	return false;	
}
bool is_fibonacci(long double n)
{
	return is_perfect_sq(5*n*n+4) || is_perfect_sq(5*n*n-4);
}
int main()
{
	unsigned long int t;
	long double n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(is_fibonacci(n))
			cout<<"IsFibo\n";
		else
			cout<<"IsNotFibo\n";
	}
}
