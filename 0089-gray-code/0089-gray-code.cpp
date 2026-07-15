class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        int track = 0;
        for (int i = 1; i <= n; i++)
            if (i == 1) {
                ans[track++] = 0;
                ans[track++] = 1;
            } else {
                int size = track;
                for (int j = size - 1; j >= 0; j--)
                    ans[track++] = (1 << (i - 1)) | ans[j];
            }

        return ans;
    }
};