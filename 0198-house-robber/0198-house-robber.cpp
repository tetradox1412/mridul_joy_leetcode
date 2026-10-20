class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = nums[1];
        int maxi = dp[0];
        for (int i = 2; i < n; i++) {
            dp[i] = nums[i] + maxi;
            maxi = max(maxi, dp[i - 1]);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};