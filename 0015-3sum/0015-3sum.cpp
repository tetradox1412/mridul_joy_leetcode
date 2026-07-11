class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        if (nums.size() < 3)
            return res;

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int start = i + 1, end = nums.size() - 1;
            int target = -1 * nums[i];
            while (start < end) {
                int currSum = nums[start] + nums[end];

                if (currSum < target)
                    start++;
                else if (currSum > target)
                    end--;
                else {
                    vector<int> triplet = {nums[i], nums[start], nums[end]};
                    res.push_back(triplet);

                    start++;
                    end--;

                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                }
            }
        }
        return res;
    }
};