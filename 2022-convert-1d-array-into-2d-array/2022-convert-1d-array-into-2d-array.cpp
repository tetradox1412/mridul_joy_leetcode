class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((m * n) != original.size()) {
            vector<vector<int>> mat;
            return mat;
        }

        vector<vector<int>> mat(m, vector<int>(n, 0));
        int row = 0;
        for (int i = 0; i < original.size(); i++) {
            mat[row][i % n] = original[i];
            if ((i % n) == n - 1)
                row++;
        }
        return mat;
    }
};