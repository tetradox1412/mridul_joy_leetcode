class Solution {
public:
    bool check(vector<int>& nums) {
        int dips = 0;
        int n = nums.size();

        int idx_min = 0;
        int mini = nums[0];

        for (int i = 0; i < n; i++)
            if (min(mini, nums[i]) != mini) {
                mini = nums[i];
                idx_min = i;
            }

        for (int i = idx_min, count_el = 1; count_el <= n; i++, count_el++) {
            if (nums[i % n] > nums[(i + 1) % n])
                dips++;
        }
        return !(dips > 1);
    }
};