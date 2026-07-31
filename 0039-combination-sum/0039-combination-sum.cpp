class Solution {
public:
    void funcHelp(vector<int>& candidates, int target, vector<int> runningSum,
                  int sum, vector<vector<int>>& ans, int idx) {
        if (sum == target) {
            ans.push_back(runningSum);
            return;
        }

        if (idx == candidates.size() || sum > target)
            return;

        funcHelp(candidates, target, runningSum, sum, ans, idx + 1);
        runningSum.push_back(candidates[idx]);
        funcHelp(candidates, target, runningSum, sum + candidates[idx], ans,
                 idx);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        funcHelp(candidates, target, {}, 0, ans, 0);
        return ans;
    }
};