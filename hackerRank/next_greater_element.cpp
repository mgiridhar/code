#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void next_great_element(unsigned int arr[], unsigned int n){
    stack<unsigned int> s;
    s.push(arr[0]);
    unsigned int next;
    map<unsigned int, long int> nge;
    for(unsigned int i=1; i<n; i++){
        next = arr[i];
        while(!s.empty() && s.top()<next){
            //cout << s.top() <<" "<< next <<endl;
            nge.insert(pair<unsigned int, long int>(s.top(), next));
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty()){
        //cout << s.top() << " -1" <<endl;
        nge.insert(pair<unsigned int, long int>(s.top(), -1));
        s.pop();
    }
    for(unsigned int i=0; i<n; i++){
        cout << arr[i] << " " << nge[arr[i]] <<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int n;
    cin >> n;
    unsigned int arr[n];
    for(unsigned int i=0; i<n; i++)
        cin >> arr[i];
    next_great_element(arr, n);
    return 0;
}
