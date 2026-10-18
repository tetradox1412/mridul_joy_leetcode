class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                vec.push_back(nums[i]);
        for (int j = vec.size(); j < n; j++)
            vec.push_back(0);
        for (int i = 0; i < n; i++)
            nums[i] = vec[i];
    }
};