class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int mini = 1001;
        int maxi = 0;
        for (auto x : nums) {
            maxi = max(x, maxi);
            mini = min(x, mini);
        }
        return gcd(maxi, mini);
    }
};