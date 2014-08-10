#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s;
    cin>>s;
    long int alpha_count[26];
    for(int i=0;i<26;i++){
        alpha_count[i]=0;
    }
    
    for(long int i=0;i<s.size();i++){
        alpha_count[s[i]-97]++;
    }
    int odd_count=0;
    int flag = 1;
    
    /*for(int i=0;i<26;i++){
        cout<<alpha_count[i];
    }*/
    
    for(int i=0;i<26;i++){
        if(alpha_count[i]&1){
            odd_count++;
        }
        if(odd_count>1){
            flag = 0;
            break;
        }
    }
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}

