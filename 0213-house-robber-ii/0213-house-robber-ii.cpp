class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n - 1, 0);
        dp[0] = nums[0], dp[1] = nums[1];
        int maxi = dp[0];
        for (int i = 2; i < n - 1; i++) {
            dp[i] = nums[i] + maxi;
            maxi = max(maxi, dp[i - 1]);
        }
        int round1 = max(dp[n - 2], dp[n - 3]);

        dp[0] = nums[1], dp[1] = nums[2];
        maxi = dp[0];
        for (int i = 3; i < n; i++) {
            dp[i-1] = nums[i] + maxi;
            maxi = max(maxi, dp[i - 2]);
        }
        int round2 = max(dp[n - 2], dp[n - 3]);

        return max(round1, round2);
    }
};