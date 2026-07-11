class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max_count_idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[max_count_idx])
                count++;
            else {
                count--;
                if (count < 0) {
                    max_count_idx = i;
                    count = 0;
                }
            }
        }
        return nums[max_count_idx];
    }
};