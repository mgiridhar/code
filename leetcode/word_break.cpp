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
        
        vector<bool> dp(s.length(), false);
        for(int i=0; i<s.length(); i++) {
            for(int j=0; j<=i; j++) {
                //cout << (j > 0 && dp[j-1]) << " " << (dict.find(s.substr(j, i-j+1)) != dict.end()) << " " << s.substr(j, i-j+1) << " ";
                dp[i] = (j > 0 ? dp[j-1] : true) && (dict.find(s.substr(j, i-j+1)) != dict.end());
                if(dp[i] == true)
                    break;
            }
            //cout << i << " " << dp[i] << endl;
        }
        return dp[s.length()-1];
    }
};