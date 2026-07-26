class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 3)
            return nums[0] * nums[1] * nums[2];

        vector<int> large(3, -1001);
        vector<int> small(3, 1001);

        for (auto x : nums) {
            if (x > large[0]) {
                large[2] = large[1];
                large[1] = large[0];
                large[0] = x;
            } else if (x > large[1]) {
                large[2] = large[1];
                large[1] = x;
            } else if (x > large[2])
                large[2] = x;

            if (x < small[0]) {
                small[2] = small[1];
                small[1] = small[0];
                small[0] = x;
            } else if (x < small[1]) {
                small[2] = small[1];
                small[1] = x;
            } else if (x < small[2])
                small[2] = x;
        }

        return max(
            max(large[0] * large[1] * large[2], small[0] * small[1] * small[2]),
            max(large[0] * large[1] * small[0],
                small[0] * small[1] * large[0]));
    }
};