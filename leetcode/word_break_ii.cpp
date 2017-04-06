/*
 *** DP solution - O(n) space and time complexity *** 
 */

class Solution {
public:
    void wordBreakUtil(string s, vector<vector<int>> dp, int i, vector<string> &res) {
        if(i <= 0) {
            //cout << s << endl;
            res.push_back(s);
            return;
        }
        if(i != dp.size()-1) {
            s.insert(i, " ");
        }
        for(int j=0; j<dp[i].size(); j++) {
            wordBreakUtil(s, dp, dp[i][j], res);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0; i<wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        vector<vector<int>> dp(s.length()+1);
        dp[0].push_back(-1);
        for(int i=1; i<=s.length(); i++) {
            for(int j=1; j<=i; j++) {
                if(dp[j-1].size() && dict.find(s.substr(j-1, i-j+1)) != dict.end()) {
                    dp[i].push_back(j-1);
                }
            }
        }
        /*for(int i=0; i<dp.size(); i++) {
            for(int j=0; j<dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        vector<string> res;
        wordBreakUtil(s, dp, dp.size()-1, res);
        return res;
    }
};