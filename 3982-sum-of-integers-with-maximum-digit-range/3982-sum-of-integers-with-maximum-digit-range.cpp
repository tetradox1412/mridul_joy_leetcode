class Solution {
public:
    int extractDigitRange(int num) {
        int maxDigit = 0;
        int minDigit = 9;

        while (num > 0) {
            int digit = num % 10;
            num = num / 10;
            maxDigit = max(maxDigit, digit);
            minDigit = min(minDigit, digit);
        }
        return maxDigit - minDigit;
    }

    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitRange(n);
        int maxRange = 0;
        for (int i = 0; i < n; i++) {
            digitRange[i] = extractDigitRange(nums[i]);
            maxRange = max(maxRange, digitRange[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            if (digitRange[i] == maxRange)
                sum += nums[i];
        return sum;
    }
};