class Solution {
public:
    int maxProduct(vector<int>& nums) {
        for (auto& x : nums)
            x--;

        int max = 0;
        int max_2 = 0;

        for (auto& x : nums) {
            if (x > max) {
                max_2 = max;
                max = x;
            } else if (x > max_2)
                max_2 = x;
        }

        return max * max_2;
    }
};