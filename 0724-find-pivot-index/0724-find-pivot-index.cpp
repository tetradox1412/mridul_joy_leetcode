class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = 0;
        int rightSum = 0;
        int leftSum = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++)
            rightSum += nums[i];

        if (rightSum == leftSum)
            return pivot;

        pivot++;
        while (pivot < n) {
            leftSum += nums[pivot - 1];
            rightSum -= nums[pivot];
            if (leftSum == rightSum)
                return pivot;
            pivot++;
        }
        return -1;
    }
};