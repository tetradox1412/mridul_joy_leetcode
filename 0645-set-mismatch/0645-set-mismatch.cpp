class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 0);
        for (auto x : nums)
            vec[x - 1]++;

        vector<int> ans(2);
        for (int i = 0; i < n; i++) {
            if (vec[i] == 2)
                ans[0] = i + 1;

            if (vec[i] == 0)
                ans[1] = i + 1;
        }
        return ans;
    }
};