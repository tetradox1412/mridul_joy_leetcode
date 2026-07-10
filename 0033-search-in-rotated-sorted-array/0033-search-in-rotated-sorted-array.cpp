class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            if (low == high && nums[low] == target)
                return low;

            int mid = low + (high - low) / 2;

            if (target == nums[mid])
                return mid;

            if (nums[mid] >= nums[low] && target >= nums[low] &&
                target < nums[mid])
                high = mid - 1;
            else if (nums[mid] >= nums[low] &&
                     (target > nums[mid] || target < nums[low]))
                low = mid + 1;
            else if (nums[mid] <= nums[high] && target <= nums[high] &&
                     target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};