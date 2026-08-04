class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        vector<int> ans;
        vector<int> num_track(101, 0);

        for (auto& x : nums) {
            maxi = max(maxi, x);
            mini = min(mini, x);
        }

        for (auto& x : nums)
            num_track[x]++;

        for (int i = mini; i <= maxi; i++)
            if (num_track[i] == 0)
                ans.push_back(i);

        return ans;
    }
};