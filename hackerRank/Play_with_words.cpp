/*
You will be given a string of lowercase English alphabet letters. You have to find two palindrome which 
are non-overlapping subsequences such that the product of their lengths is maximised.

(Subsequence: It is a string derived from deleting some elements without altering order.
AC is a subsequence of ABCD; BA is not.)

Let's say P and Q be two subsequences. Pi and Pj are the indices of first and last characters of P,
in basic string (Similar definition for Qi and Qj).They are non-overlapping if Pj < Qi. In other words,
the first character in subsequence Q should come only after complete appearance of subsequence P.

Basic string can have almost 3200 characters.

I/p format:
Input contain one string only(Sequence of non-separated characters).

output
The product value for each String.

Sample Input:
aaapaaskmywbcaajjaacb

Sample Output:
50

Reason:
P:- aaaaa (5)
Q:- bcaajjaacb (10)
5*10 = 50

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxProdNOLPS(string s) {
    if(s.length() == 0)
        return 0;
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    for(int i=0; i<s.length(); i++) {
        dp[i][i] = 1;
        if(i+1 < s.length()) {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
    }
    for(int l=2; l < s.length(); l++) {
        for(int i=0; (i + l) < s.length(); i++) {
            int j = i + l;
            if(s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    int maxProd = 1;
    for(int i=0; i < s.length()-1; i++) {
        maxProd = max(maxProd, dp[0][i] * dp[i+1][s.length()-1]);
    }
    return maxProd;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    cout << maxProdNOLPS(s);
    return 0;
}

// Time - O(n^2)
// Space - O(n^2)
