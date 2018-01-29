/*
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5]

Time Complexity - ?
Space Complexity - ?
*/
class Solution {
public:
    
    bool isValid(int i, int j) {
        if(i < 0 || j < 0 || i >= 2 || j >= 3)
            return false;
        return true;
    }
    
    bool checkSolved(vector<vector<int>>& board) {
        if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0)
            return true;
        return false;
    }
    
    bool isVisited(vector<vector<int>>& board, unordered_set<string> &visited) {
        string s = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
        //cout << s << endl;
        if(visited.find(s) != visited.end())
            return true;
        visited.insert(s);
        return false;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<vector<vector<int>>,pair<int,int>>> q;
        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    q.push({board, {i, j}});
                    break;
                }
            }
        }
        
        int steps = 0;
        unordered_set<string> visited;
        isVisited(board, visited);
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                board = q.front().first;
                pair<int,int> zero = q.front().second;
                q.pop();
                if(checkSolved(board))
                    return steps;
                vector<pair<int,int>> neighs = {{1,0},{-1,0},{0,1},{0,-1}};
                for(int i=0; i<4; i++) {
                    int x = zero.first + neighs[i].first, y= zero.second + neighs[i].second;
                    if(isValid(x, y)) {
                        swap(board[zero.first][zero.second], board[x][y]);
                        if(!isVisited(board, visited)) {
                            q.push({board, {x,y}});
                        }
                        swap(board[zero.first][zero.second], board[x][y]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
