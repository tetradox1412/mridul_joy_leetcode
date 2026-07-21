class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for (auto x : words) {
            int sum = 0;
            for (auto y : x)
                sum += weights[y - 'a'];
            s += (char)('z' - (sum % 26));
        }
        return s;
    }
};