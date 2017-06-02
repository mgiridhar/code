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
    
    /*** dp solution - 22 ms ***/
    vector<vector<string>> partition(string s) {
        if(s.length() == 0) return vector<vector<string>>();
        
        vector<vector<vector<string>>> dp(s.length());
        //dp[0].push_back(vector<string>());
        dp[0].push_back(vector<string>(1, string(1, s[0])));
        for(int i=1; i<s.length(); i++) {
            //copy all the previous partitioned strings with the current additional character
            for(int k=0; k<dp[i-1].size(); k++) {
                dp[i].push_back(dp[i-1][k]);
                dp[i][k].push_back(string(1, s[i]));
            }
            //check for palindrome
            for(int j=0; j<i; j++) {
                if(s[j] == s[i] && isPalindrome(s.substr(j, i-j+1))) {
                    if(j == 0) {
                        dp[i].push_back(vector<string>(1, s.substr(j, i-j+1)));
                    }
                    else {
                        int curr_len = dp[i].size();
                        for(int k=0; k<dp[j-1].size(); k++) {
                            dp[i].push_back(dp[j-1][k]);
                            dp[i][curr_len + k].push_back(s.substr(j, i-j+1));
                        }
                    }
                }
            }
        }
        /*for(int i=0; i<dp.size(); i++) {
            cout << "[" ;
            for(int j=0; j<dp[i].size(); j++) {
                cout << "[" ;
                for(int k=0; k<dp[i][j].size(); k++) {
                    cout << dp[i][j][k] << ", ";
                }
                cout << "], ";
            }
            cout << "]" << endl;
        }*/
        return dp[s.length()-1];
    }
    
    /*
    *** backtracking - exponential time - 19 ms ***
    
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
    */
};