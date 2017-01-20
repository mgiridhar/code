class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.length()+1][s.length()+1];
        int i,j;
        dp[0][0] = true;
        for(j=1; j<=s.length(); j++)
            dp[0][j] = false;
        for(i=1; i<=p.length(); i++)
            dp[i][0] = false;
        i=0;
        while(p[i] == '*') {
                dp[i+1][0] = true;
                i++;
        }
        for(i=1; i<=p.length(); i++) 
        {
            for(j=1; j<=s.length(); j++)
            {
                if(s[j-1] == p[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[p.length()][s.length()];
    }
};