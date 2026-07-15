class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;

        for (int i = 1; i <= n; i++)
            if (i == 1) {
                ans.push_back(0);
                ans.push_back(1);
            } else {
                int size = ans.size();
                for (int j = size - 1; j >= 0; j--)
                    ans.push_back((1 << (i - 1)) | ans[j]);
            }

        return ans;
    }
};