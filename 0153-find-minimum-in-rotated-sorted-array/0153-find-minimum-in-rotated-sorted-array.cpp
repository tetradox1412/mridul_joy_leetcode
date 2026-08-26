class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high) {
        if (high - low <= 1)
            return min(nums[high], nums[low]);

        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
            return binarySearch(nums, mid + 1, high);
        else
            return binarySearch(nums, low, mid);
    }

    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};