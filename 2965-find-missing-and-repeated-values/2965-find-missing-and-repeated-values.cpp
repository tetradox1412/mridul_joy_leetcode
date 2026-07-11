class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();

        int num_diff = 0, num_square_diff = 0;

        for (int i = 0; i < n * n; i++) {
            int content = grid[i / n][i % n];
            num_diff += (i + 1) - content;
            num_square_diff += ((i + 1) - content) * ((i + 1) + content);
        }

        int num_sum = num_square_diff / num_diff;

        int temp = (num_sum + num_diff) / 2;
        int count = 0;
        for (int i = 0; i < n * n; i++) {
            if (grid[i / n][i % n] == temp) {
                count++;
                break;
            }
        }

        int a, b;

        if (count) {
            a = temp;
            b = num_sum - temp;
        } else {
            b = temp;
            a = num_sum - temp;
        }

        vector<int> ans = {a, b};
        return ans;
    }
};