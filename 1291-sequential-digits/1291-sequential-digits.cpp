class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digitsInLow = log10(low) + 1;
        int digitsInHigh = log10(high) + 1;

        int digitCount = digitsInLow;
        vector<int> answer;

        while (digitCount <= digitsInHigh) {

            // Creating digit mask & base number
            int baseNum = 1, mask = 1;
            for (int i = 1; i < digitCount; i++) {
                baseNum *= 10;
                baseNum += i + 1;
                mask *= 10;
                mask += 1;
            }

            // Adding sequentials to the vector
            int num = baseNum;
            while ((int)log10(num) + 1 == digitCount && num % 10 != 0) {
                if (num >= low && num <= high)
                    answer.push_back(num);
                num += mask;
            }
            digitCount++;
        }
        return answer;
    }
};