/* Stack problem */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> waiter(vector<int> &number, int q, vector<bool> &primes) {
    if(q < 1) return number;
    int j = 2;
    vector<int> result;
    vector<stack<int>> A(q+1), B(q+1);
    for(int k=0; k<number.size(); k++)
        A[0].push(number[k]);
    //cout << "pass1 ";
    for(int i=1; i<=q; i++) {
        while(primes[j] == false) j++;
        for(int k=j+j; k<primes.size(); k+=j)
            primes[k] = false;
        //cout << "pass2 " << j << " ";
        int top;
        while(!A[i-1].empty()) {
            top = A[i-1].top();
            A[i-1].pop();
            //cout << top << " " ;
            if(top % j == 0) {
                B[i].push(top);
            }
            else {
                A[i].push(top);
            }
        }
        while(!B[i].empty()) {
            result.push_back(B[i].top());
            B[i].pop();
        }
        j++;
    }
    while(!A[q].empty()) {
        result.push_back(A[q].top());
        A[q].pop();
    }
    return result;
}

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> number(n);
    for(int number_i = 0; number_i < n; number_i++){
       cin >> number[number_i];
    }
    vector<bool> primes(10000, true);
    primes[0] = false;
    primes[1] = false;
    vector<int> result = waiter(number, q, primes);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }  
    return 0;
}
