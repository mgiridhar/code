class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        int maxLen = 1, start=0;
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = 0;;
            }
        }*/
        memset(dp, 0, sizeof(dp));
        
        //k - substrings of length 1
        //k=1
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        //k=2
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
                maxLen = 2;
                start = i;
            }
        }
        //k=3 to n
        for(int k=3; k<=n; k++){
            for(int i=0; i<=n-k; i++){
                int j = i+k-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if(maxLen < dp[i][j]){
                        maxLen = dp[i][j];
                        start = i;
                    }
                }
            }
        }
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return s.substr(start, maxLen);
    }
};