#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long int n,num;
    int digit;
    while(t--){
        cin>>n;
        long long int sum = 0;
        num = n;
	while(n){
            digit = n%10;
            if(digit && !(num%digit))
                sum++;               
            n/=10;
        }
        cout<<sum<<'\n';
    }
}
