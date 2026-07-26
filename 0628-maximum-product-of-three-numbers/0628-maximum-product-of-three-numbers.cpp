class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 3)
            return nums[0] * nums[1] * nums[2];

        int large_1 = -1001;
        int large_2 = -1001;
        int large_3 = -1001;

        int small_1 = 1001;
        int small_2 = 1001;
        int small_3 = 1001;

        for (auto x : nums) {
            if (x > large_1) {
                large_3 = large_2;
                large_2 = large_1;
                large_1 = x;
            } else if (x > large_2) {
                large_3 = large_2;
                large_2 = x;
            } else if (x > large_3)
                large_3 = x;

            if (x < small_1) {
                small_3 = small_2;
                small_2 = small_1;
                small_1 = x;
            } else if (x < small_2) {
                small_3 = small_2;
                small_2 = x;
            } else if (x < small_3)
                small_3 = x;
        }

        return max(
            max(large_1 * large_2 * large_3, small_1 * small_2 * small_3),
            max(large_1 * large_2 * small_1, small_1 * small_2 * large_1));
    }
};