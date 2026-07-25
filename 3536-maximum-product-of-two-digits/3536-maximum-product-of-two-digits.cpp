class Solution {
public:
    int maxProduct(int n) {
        int highest = 0;
        int secondHighest = 0;
        while (n > 0) {
            int digit = n % 10;

            if (digit > highest) {
                swap(highest, secondHighest);
                highest = digit;
                n /= 10;
                continue;
            }

            secondHighest = max(digit, secondHighest);
            n /= 10;
        }
        return highest * secondHighest;
    }
};