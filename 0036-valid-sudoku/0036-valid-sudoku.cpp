class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col) {
        char val = board[row][col];
        for (int i = 0; i < 9; i++)
            if (board[row][i] == val && i != col)
                return false;

        for (int i = 0; i < 9; i++)
            if (board[i][col] == val && i != row)
                return false;

        int gridRow = (int)(row / 3) * 3;
        int gridCol = (int)(col / 3) * 3;
        for (int i = gridRow; i < gridRow + 3; i++)
            for (int j = gridCol; j < gridCol + 3; j++)
                if (i != row && j != col && board[i][j] == val)
                    return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] > '0' && board[i][j] <= '9' &&
                    !isSafe(board, i, j))
                    return false;
        return true;
    }
};