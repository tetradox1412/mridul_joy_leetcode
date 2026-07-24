class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> map;
        int n = strs.size();

        vector<string> strCpy;
        for (auto x : strs) {
            sort(x.begin(), x.end());
            strCpy.push_back(x);
        }

        for (int i = 0; i < n; i++)
            map[strCpy[i]].push_back(i);

        for (auto x : map) {
            vector<string> temp;
            for (auto y : x.second)
                temp.push_back(strs[y]);

            ans.push_back(temp);
        }

        return ans;
    }
};