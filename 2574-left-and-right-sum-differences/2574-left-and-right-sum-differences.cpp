class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int sum = 0;
        for (auto x : nums)
            sum += x;

        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            ans[i] = abs(rightSum - leftSum);
            leftSum += nums[i];
        }

        return ans;
    }
};
