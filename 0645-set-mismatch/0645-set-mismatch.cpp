class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec(2);
        int n = nums.size();

        int properXOR = 0;
        for (int i = 0; i < n; i++)
            properXOR ^= i + 1;

        int wrongXOR = 0;
        for (int i = 0; i < n; i++)
            wrongXOR ^= nums[i];

        int mixXOR = wrongXOR ^ properXOR;

        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1]) {
                vec[0] = nums[i];
                break;
            }

        vec[1] = mixXOR ^ vec[0];

        return vec;
    }
};