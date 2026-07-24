class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto x : nums) {
            vector<int> digits;
            while (x > 0) {
                digits.push_back(x % 10);
                x = x / 10;
            }
            for (int i = digits.size() - 1; i >= 0; i--)
                ans.push_back(digits[i]);
        }

        return ans;
    }
};