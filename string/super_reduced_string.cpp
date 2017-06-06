/*
Steve has a string, , consisting of  lowercase English alphabetic letters. In one operation, he can delete any pair of adjacent letters with same value. For example, string "aabcc" would become either "aab" or "bcc" after operation.

Steve wants to reduce  as much as possible. To do this, he will repeat the above operation as many times as it can be performed. Help Steve out by finding and printing 's non-reducible form!

Note: If the final string is empty, print Empty String .

Input Format

A single string, .

Constraints


Output Format

If the final string is empty, print Empty String; otherwise, print the final non-reducible string.

Sample Input 0

aaabccddd
Sample Output 0

abd
Sample Case 0

Steve can perform the following sequence of operations to get the final string:

aaabccddd → abccddd
abccddd → abddd
abddd → abd
Thus, we print abd.

Sample Input 1

baab
Sample Output 1

Empty String
Explanation 1

Steve can perform the following sequence of operations to get the final string:

baab → bb
bb → Empty String
Thus, we print Empty String.

Sample Input 2

aa
Sample Output 2

Empty String
Explanation 2

Steve can perform the following sequence of operations to get the final string:

aa → Empty String
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string reducedString(string s) {
    if(s.length() == 0)
        return "Empty String";
    vector<char> v;
    v.push_back(s[0]);
    int top=0;
    for(int i=1; i < s.length(); i++) {
        if(top >= 0 && s[i] == v[top]) {
            v.pop_back();
            top--;
        }
        else {
            v.push_back(s[i]);
            top++;
        }
    }
    
    if(v.size() == 0)
        return "Empty String";
    
    string rs = "";
    for(int i = 0; i<v.size(); i++) {
        rs += v[i];
    }
    return rs;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s ;
    cout << reducedString(s) << endl;
    return 0;
}

