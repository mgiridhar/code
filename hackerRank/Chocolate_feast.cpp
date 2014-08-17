#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    long int n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        long int answer=0;
        // Computer answer
        answer = n/c;
	long int temp = (answer/m) + (answer%m);
        answer += answer/m; 
        while(temp >= m){
            answer += temp/m;
            temp = (temp/m) + (temp%m);
        }
        cout<<answer<<endl;
    }
    return 0;
}

