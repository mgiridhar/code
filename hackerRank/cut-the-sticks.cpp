#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i,small_no;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        //if(a[i]<small_no)
        //    small_no = a[i];
    }
    int count;
    while(true){
        count = 0;
        small_no = INT_MAX;
        for(i=0;i<n;i++) {
            if(a[i]>0 && a[i]<small_no)
                small_no=a[i];
        }
        for(i=0;i<n;i++) {
            if(a[i] > 0) {
                a[i] = a[i] - small_no;
                count++;
            }
        }
        if(count==0)
            break;
        cout<<count<<'\n';
    }
    return 0;
}
