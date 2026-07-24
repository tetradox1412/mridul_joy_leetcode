class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (nums[i] > 0) {
                s.push(nums[i] % 10);
                nums[i] /= 10;
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};