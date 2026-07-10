class Solution {
public:
    int binary_search(vector<int>& nums, int target, int low, int high) {
        if (low <= high) {

            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else {
                if (target > nums[mid])
                    return binary_search(nums, target, mid + 1, high);
                else
                    return binary_search(nums, target, low, mid - 1);
            }
        } else
            return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binary_search(nums, target, 0, n - 1);
    }
};