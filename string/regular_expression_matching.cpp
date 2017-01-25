class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i,j;
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for(i=1; i<=m; i++)
            dp[i][0] = false;
        for(j=1; j<=n; j++)
            dp[0][j] = false;
        j=1;
        while(j<n && p[j] == '*')
        {
            dp[0][j+1] = true;
            j += 2;
        }
        for(i=0; i<m; i++) 
        {
            for(j=0; j<n; j++) 
            {
                if(s[i] == p[j] || p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*')
                {
                    dp[i+1][j+1] = dp[i+1][j-1]; //consider 0 occurrence of the pattern
                    if(p[j-1] == s[i] || p[j-1] == '.') // consider one occurrence of the pattern
                    {
                        dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1];
                    }
                }
                else
                    dp[i+1][j+1] = false;
            }
        }
        for(i=0; i<=m; i++) 
        {
            for(j=0; j<=n; j++) 
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};