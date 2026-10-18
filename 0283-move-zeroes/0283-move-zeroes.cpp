class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == 0)
                for (int j = i + 1; j < n; j++) {
                    if (j == n - 1 && nums[j] == 0)
                        return;
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
    }
};