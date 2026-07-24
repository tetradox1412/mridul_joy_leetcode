class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        int n = strs.size();

        for (auto& x : strs) {
            string p = x;
            sort(x.begin(), x.end());
            map[x].push_back(p);
        }

        for (auto& x : map)
            ans.push_back(x.second);

        return ans;
    }
};