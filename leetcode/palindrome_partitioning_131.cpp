/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
/*** backtracking - exponential time ***/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 1) return true;
        for(int i=0; i<(s.length()/2); i++) {
            if(s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }
    
    void partition(string s, int i, vector<vector<string>> &result, vector<string> tempRes) {
        if(i >= s.length()) {
            result.push_back(tempRes);
            return;
        }
        
        for(int j=i; j<s.length(); j++) {
            if(isPalindrome(s.substr(i, j-i+1))){
                tempRes.push_back(s.substr(i, j-i+1));
                partition(s, j+1, result, tempRes);
                tempRes.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> tempRes;
        vector<vector<string>> res;
        partition(s, 0, res, tempRes);
        return res;
    }
};