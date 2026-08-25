class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int totalProduct = 1;
        int count0 = 0;

        for (int& x : nums) {
            if (x == 0)
                count0++;
            else
                totalProduct *= x;
        }

        if (count0 > 1) {
            for (int i = 0; i < n; i++)
                ans[i] = 0;
            return ans;
        }

        if (count0) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0)
                    ans[i] = totalProduct;
                else
                    ans[i] = 0;
            }
        } else
            for (int i = 0; i < n; i++)
                ans[i] = totalProduct / nums[i];

        return ans;
    }
};