class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;
        while (true) {
            int pro = 1;
            int ans_cpy = ans;
            while (ans_cpy > 0) {
                pro *= ans_cpy % 10;
                ans_cpy /= 10;
            }
            if (!(pro % t))
                return ans;
            else
                ans++;
        }
    }
};