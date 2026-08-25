class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto& x : nums)
            set.insert(x);

        return !(set.size() == nums.size());
    }
};