class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto& x : nums)
            map[x]++;

        vector<pair<int, int>> vec;
        for (auto& x : map)
            vec.push_back({x.second, x.first});
        sort(vec.rbegin(), vec.rend());

        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(vec[i].second);
        return ans;
    }
};