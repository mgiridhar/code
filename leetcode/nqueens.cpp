class Solution {
	public:
	    vector<vector<string>> solutions;

	    vector<string> initialize_board(int n)
	    {
		vector<string> temp;
		for(int i=0; i<n; i++)
		{
		    string s(n, '.');
		    temp.push_back(s);
		}
		return temp;
	    }
	    vector<string> makeDeepCopy(vector<string> board)
	    {
		vector<string> copy;
		for(int i=0; i<board.size(); i++)
		{
		    string newS = board[i];
		    copy.push_back(newS);
		}
		return copy;
	    }
	    
	    vector<vector<string>> solveNQueens(int n)
	    {
		NQueens(initialize_board(n), 0, n);
		return solutions;
	    }
	    void NQueens(vector<string> board, int row, int n)
	    {
		if(row >= n)
		{
		    solutions.push_back(makeDeepCopy(board));
		    return;
		}
		for(int j=0; j<n; j++)
		{
		    if(!safe_place(board, row, j))
			continue;
		    board[row][j] = 'Q';
		    NQueens(board, row+1, n);
		    board[row][j] = '.';
		}
	    }
	    bool safe_place(vector<string> board, int row, int column)
	    {
		//same row - no need to check because we are placing the queen only on the new row.
		//check same column
		for(int i=0; i<row; i++)
		{
		    if(board[i][column] == 'Q')
			return false;
		}
		//check upper back diagonal
		for(int i=row-1, j=column-1; i>=0 && j>=0; i--, j--)
		{
		    if(board[i][j] == 'Q')
			return false;
		}
		//check upper front diagonal
		for(int i=row-1, j=column+1; i>=0 && j<board[i].size(); i--, j++)
		{
		    if(board[i][j] == 'Q')
			return false;
		}
		return true;
	    }
};
