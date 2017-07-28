/***
http://www.geeksforgeeks.org/collect-maximum-coins-before-hitting-a-dead-end/
***/
/*
 *
Given a character matrix where every cell has one of the following values.

'C' -->  This cell has coin

'#' -->  This cell is a blocking cell.
         We can not go anywhere from this.

'E' -->  This cell is empty. We don't get
         a coin, but we can move from here.
Initial position is cell (0, 0) and initial direction is right.

Following are rules for movements across cells.

If face is Right, then we can move to below cells

Move one step ahead, i.e., cell (i, j+1) and direction remains right.
Move one step down and face left, i.e., cell (i+1, j) and direction becomes left.
If face is Left, then we can move to below cells

Move one step ahead, i.e., cell (i, j-1) and direction remains left.
Move one step down and face right, i.e., cell (i+1, j) and direction becomes right.
Final position can be anywhere and final direction can also be anything. The target is to collect maximum coins.
 *
 */
#include<iostream>
#include<vector>
using namespace std;

int maxCoinsCollected(vector<vector<char>> matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxCoins = 0;
    dp[0][0] = 0;
    for(int j=1; j<m; j++) {
        if(matrix[0][j] == '#') break;
        else if(matrix[0][j] == 'C')
            dp[0][j] = dp[0][j-1] + 1;
        else
            dp[0][j] = dp[0][j-1];
    }
    for(int i=1; i<n; i++) {
        if(i%2) {
            if(matrix[i][m-1] != '#' && dp[i-1][m-1] >= 0)
                dp[i][m-1] = (matrix[i][m-1] == 'C') ? dp[i-1][m-1] + 1 : dp[i-1][m-1];
            maxCoins = max(maxCoins, dp[i][m-1]);
            for(int j=m-2; j>=0; j--) {
                if(matrix[i][j] != '#') {
                    if (dp[i - 1][j] >= 0)
                        dp[i][j] = max(dp[i][j], (matrix[i][j] == 'C') ? dp[i - 1][j] + 1 : dp[i - 1][j]);
                    if (dp[i][j + 1] >= 0)
                        dp[i][j] = max(dp[i][j], (matrix[i][j] == 'C') ? dp[i][j + 1] + 1 : dp[i][j + 1]);
                }
                maxCoins = max(maxCoins, dp[i][j]);
            }
        }
        else {
            if(matrix[i][0] != '#' && dp[i-1][0] >= 0)
                dp[i][0] = (matrix[i][0] == 'C') ? dp[i-1][0] + 1 : dp[i-1][0];
            maxCoins = max(maxCoins, dp[i][0]);
            for(int j=1; j<m; j++) {
                if(matrix[i][j] != '#') {
                    if(dp[i-1][j] >= 0)
                        dp[i][j] = max(dp[i][j], (matrix[i][j] == 'C') ? dp[i-1][j] + 1 : dp[i-1][j]);
                    if(dp[i][j-1] >= 0)
                        dp[i][j] = max(dp[i][j], (matrix[i][j] == 'C') ? dp[i][j-1] + 1 : dp[i][j-1]);
                }
                maxCoins = max(maxCoins, dp[i][j]);
            }
        }
    }
    return maxCoins;
}

int main() {
    vector<vector<char>> matrix = { {'E', 'C', 'C', 'C', 'C'},
                                    {'C', '#', 'C', '#', 'E'},
                                    {'#', 'C', 'C', '#', 'C'},
                                    {'C', 'E', 'E', 'C', 'E'},
                                    {'C', 'E', '#', 'C', 'E'}
                                    };
    cout << "Maximum number of collected coins is " << maxCoinsCollected(matrix) << endl;
    return 0;
}