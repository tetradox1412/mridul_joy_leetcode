class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool permValid = false;
        int n = nums.size();
        int i;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                permValid = true;
                break;
            }
        }

        if (!permValid)
            sort(nums.begin(), nums.end());
        else {
            int j = n - 1;
            for (; j > i && nums[j] <= nums[i]; j--)
                ;

            swap(nums[i], nums[j]);
            int l = i + 1, r = n - 1;
            while (l < r)
                swap(nums[l++], nums[r--]);
        }
    }
};