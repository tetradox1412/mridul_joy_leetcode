class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = 36;
        for (auto x : nums) {
            int sum = 0;
            while (x > 0) {
                sum += (x % 10);
                x = x / 10;
            }
            mini = min(sum, mini);
        }
        return mini;
    }
};