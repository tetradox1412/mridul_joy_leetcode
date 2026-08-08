class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!s.empty() && nums[idx] > nums[s.top()]) {
                res[s.top()] = nums[idx];
                s.pop();
            }
            if (i < n)
                s.push(idx);
        }
        return res;
    }
};