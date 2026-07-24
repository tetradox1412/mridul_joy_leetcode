class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";

        int idx = 0;
        while (idx < strs[0].size()) {
            char curr = strs[0][idx];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][idx] != curr)
                    return s;
            }
            s += curr;
            idx++;
        }

        return s;
    }
};