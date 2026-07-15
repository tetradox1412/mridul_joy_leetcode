class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for (int i = 1; i <= n; i++)
            sumEven += i << 1;
        sumOdd = sumEven - n;
        cout << sumOdd << " " << sumEven;

        return gcd(sumEven, sumOdd);
    }
};