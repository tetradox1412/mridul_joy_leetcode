class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<int>> ans(rows, vector<int>(columns));
        int j;
        k = k % (rows * columns);
        for (j = 0; (j + k) < (rows * columns); j++)
            ans[(j + k) / columns][(j + k) % columns] =
                grid[j / columns][j % columns];

        int p = 0;
        for (; j < rows * columns; j++, p++)
            ans[p / columns][p % columns] = grid[j / columns][j % columns];

        return ans;
    }
};