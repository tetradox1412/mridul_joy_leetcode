class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void nQueens(vector<string>& board, int row, vector<vector<string>>& ans) {
        int n = board.size();
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
            if (isSafe(board, row, i)) {
                board[row][i] = 'Q';
                nQueens(board, row + 1, ans);
                board[row][i] = '.';
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        string chess_row = "";
        for (int i = 0; i < n; i++)
            chess_row += '.';

        vector<vector<string>> ans;
        vector<string> board(n, chess_row);
        nQueens(board, 0, ans);
        return ans;
    }
};