class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0)
            return 0;

        long int digit;
        long int ans = 0;
        long int sum = 0;

        while (n > 0) {
            digit = n % 10;
            n = n / 10;
            sum += digit;
            if (digit != 0)
                ans = ans * 10 + digit;
        }

        long int ans_rev = 0;
        while (ans > 0) {
            digit = ans % 10;
            ans = ans / 10;
            ans_rev = ans_rev * 10 + digit;
        }
        return ans_rev * sum;
    }
};