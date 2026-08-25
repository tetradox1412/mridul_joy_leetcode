class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if (n == 0 || n == 1)
            return n;

        int max_rl = 1;
        int rl = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 == nums[i - 1]) {
                rl++;
                max_rl = max(max_rl, rl);
            } else if (nums[i] == nums[i - 1])
                continue;
            else
                rl = 1;
        }
        return max_rl;
    }
};