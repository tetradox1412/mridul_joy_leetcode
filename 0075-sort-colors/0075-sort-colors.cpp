class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int temp = nums[pt];
                nums[pt++] = nums[i];
                nums[i] = temp;
            }
        }

        pt = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 2) {
                int temp = nums[pt];
                nums[pt--] = nums[i];
                nums[i] = temp;
            }
        }
    }
};