class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int x_copy = x;
        long int sum = 0;
        while (x > 0) {
            sum *= 10;
            sum += x % 10;
            x /= 10;
        }
        return sum == x_copy;
    }
};