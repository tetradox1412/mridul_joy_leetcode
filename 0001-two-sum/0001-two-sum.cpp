class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
            hashMap[nums[i]] = i;

        vector<int> res(2);

        for (int i = 0; i < nums.size(); i++)
            if (hashMap.contains(target - nums[i]) &&
                i != hashMap[target - nums[i]]) {
                res[0] = i;
                res[1] = hashMap[target - nums[i]];
                break;
            }
        return res;
    }
};