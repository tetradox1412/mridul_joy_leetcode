class Solution {
public:
    bool check(vector<int>& nums) {
        bool isDipped = false;

        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] >= nums[i - 1] && !isDipped) ||
                (nums[i] >= nums[i - 1] && isDipped && nums[i] <= nums[0]))
                continue;
            else if (nums[i] < nums[i - 1] && nums[i] <= nums[0] && !isDipped)
                isDipped = true;
            else
                return false;
        }
        return true;
    }
};