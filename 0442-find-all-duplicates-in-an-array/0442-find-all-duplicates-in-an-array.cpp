class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int j = 0; j < 10; j++)
            for (int i = 0; i < n; i++)
                swap(nums[i], nums[nums[i] - 1]);

        for (auto x : nums)
            cout << x << " ";
        cout << endl;

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                ans.push_back(nums[i]);

        return ans;
    }
};