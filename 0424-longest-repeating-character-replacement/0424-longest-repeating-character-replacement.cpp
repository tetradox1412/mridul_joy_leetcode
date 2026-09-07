class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 1;

        if (k >= n)
            return n;

        vector<bool> charPresent(26, false);
        for (auto& x : s)
            charPresent[x - 'A'] = true;

        int tempK = k;
        for (int i = 0; i < 26; i++) {
            if (charPresent[i]) {
                char rep = 'A' + i;
                int left = 0, right = 0;
                k = tempK;
                while (right < n) {
                    if (s[right] == rep)
                        right++;
                    else if (k > 0) {
                        k--;
                        right++;
                    } else {
                        ans = max(right - left, ans);
                        while (left <= right && k == 0) {
                            if (s[left] != rep)
                                k++;
                            left++;
                        }
                    }
                }
                ans = max(right - left, ans);
            }
        }

        return ans;
    }
};