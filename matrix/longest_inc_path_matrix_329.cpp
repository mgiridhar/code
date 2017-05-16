/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

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
