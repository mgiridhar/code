/*
 *** DP solution - O(n) space and time complexity ***
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty())
            return false;
            
        unordered_set<string> dict;
        for(int i=0; i<wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++) {
                
                if(dp[j]) {
                    dp[i] =  (dict.find(s.substr(j, i-j)) != dict.end());
                    
                    if(dp[i])
                        break;
                }
            }
        }
        return dp[s.length()];
    }
};