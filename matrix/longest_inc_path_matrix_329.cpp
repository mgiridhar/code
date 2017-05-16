class Solution {
public:
    
    /*** dp solution ***/
    /* gives TLE if the matrices are not passed as reference -> there can cost involved while copying the matrices to the function */
    int maxIncreasing(vector<vector<int>> &m, vector<vector<int>> &dp, int i, int j, int prev) {
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size() || (prev >= m[i][j]))
            return 0;
        if(dp[i][j] != 0)
            return dp[i][j];
        int top = (i > 0) ? maxIncreasing(m, dp, i-1, j, m[i][j]) : 0;
        int bottom = (i < m.size()-1) ? maxIncreasing(m, dp, i+1, j, m[i][j]) : 0;
        int left = (j > 0) ? maxIncreasing(m, dp, i, j-1, m[i][j]) : 0;
        int right = (j < m[0].size()-1) ? maxIncreasing(m, dp, i, j+1, m[i][j]) : 0;
        dp[i][j] = 1 + max(max(top, bottom),max(left, right));
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) 
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_inc = 1;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                max_inc = max(max_inc, maxIncreasing(matrix, dp, i, j, matrix[i][j] - 1));
            }
        }
        return max_inc;
    }
};