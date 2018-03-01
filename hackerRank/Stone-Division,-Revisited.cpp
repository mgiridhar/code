/*
You have a pile of  stones that you want to split into multiple piles, as well as a set, , of  distinct integers. We define a move as follows:

First, choose a pile of stones. Let's say that the chosen pile contains  stones.
Next, look for some  such that  and  is divisible by  (i.e.,  is a factor of ); if such an  exists, you can split the pile into  equal smaller piles.
You are given  queries where each query consists of  and . For each query, calculate the maximum possible number of moves you can perform and print it on a new line.

Input Format

The first line contains an integer, , denoting the number of queries. The  subsequent lines describe each query in the following format:

The first line contains two space-separated integers describing the respective values of  (the size of the initial pile in the query) and  (the size of the set in the query).
The second line contains  distinct space-separated integers describing the values in set .

Output Format

For each query, calculate the maximum possible number of moves you can perform and print it on a new line.

Sample Input 0

1
12 3
2 3 4
Sample Output 0

4
*/
// recursion with memoization

#include <bits/stdc++.h>

using namespace std;

long stoneDivUtil(long n, vector<long> &s, unordered_map<long,long> &hash) {
    if(hash.find(n) != hash.end())
        return hash[n];
    long maxDiv = 0, d;
    for(int i=0; i < s.size() && s[i] < n; i++) {
        if(n % s[i] != 0)
            continue;
        d = n / s[i];
        maxDiv = max((long)maxDiv, 1 + (d * stoneDivUtil(s[i], s, hash)));
    }
    //cout << n << " " << maxDiv << endl;
    hash[n] = maxDiv;
    return maxDiv;
}

long stoneDivision(long n, vector <long> s) {
    // Complete this function
    
    sort(s.begin(), s.end());
    unordered_map<long, long> hash;
    return stoneDivUtil(n, s, hash);
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long n;
        int m;
        cin >> n >> m;
        vector<long> s(m);
        for(int s_i = 0; s_i < m; s_i++){
           cin >> s[s_i];
        }
        long result = stoneDivision(n, s);
        cout << result << endl;
    }
    return 0;
}

// Time - O(m^n)
// Space - O(n + m), hash space + stack space
