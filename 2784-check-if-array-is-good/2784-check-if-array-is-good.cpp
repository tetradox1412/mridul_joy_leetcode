class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int idx = 0;
        while (idx < n - 1)
            if (nums[idx] != (idx++) + 1)
                return false;
                
        if (idx != nums[idx])
            return false;

        return true;
    }
};