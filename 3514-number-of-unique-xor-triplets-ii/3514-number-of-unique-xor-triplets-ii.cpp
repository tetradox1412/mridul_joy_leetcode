class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> finalNums;
        sort(nums.begin(), nums.end());
        finalNums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i - 1] != nums[i])
                finalNums.push_back(nums[i]);

        int n = finalNums.size();
        int maxi = finalNums[n - 1];
        int maxLimit = 2;
        while (maxi != 1) {
            maxi = maxi >> 1;
            maxLimit = maxLimit << 1;
        }

        vector<bool> two_xor(maxLimit, false);
        for (auto x : finalNums)
            for (auto y : finalNums)
                two_xor[x ^ y] = true;

        vector<bool> three_xor(maxLimit, false);
        for (auto x : finalNums)
            for (int i = 0; i < maxLimit; i++)
                if (two_xor[i])
                    three_xor[i ^ x] = true;

        int count = 0;
        for (int i = 0; i < three_xor.size(); i++)
            if (three_xor[i])
                count++;
        return count;
    }
};