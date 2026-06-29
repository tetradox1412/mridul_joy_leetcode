class Solution {
public:
    // To calculate the index of the character in the character count vector
    int chIdx(char c) {
        // If lowercase
        if (c >= 'a')
            return c - 'a' + 26;
        // Else uppercase
        return c - 'A';
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Taking count of all characters in t
        vector<int> char_count(52, numeric_limits<int>::min());
        for (int i = 0; i < n; i++) {
            int idx = chIdx(t[i]);
            if (char_count[idx] == numeric_limits<int>::min())
                char_count[idx] = 1;
            else
                char_count[idx]++;
        }

        // Finding the minimum substring
        int left = 0;
        int right = 0;
        int total_char_count = 0;
        int minLen = numeric_limits<int>::max();

        // Tracks the "left" and "right" values for the minimal substring
        vector<int> ans_edges(2);

        while (right < m) {
            if (char_count[chIdx(s[right])] != numeric_limits<int>::min()) {
                if (char_count[chIdx(s[right])] > 0)
                    total_char_count++;
                char_count[chIdx(s[right++])]--;

                while (total_char_count == n) {
                    int currLen = right - left;
                    if (currLen < minLen) {
                        minLen = currLen;
                        ans_edges[0] = left;
                        ans_edges[1] = right;
                    }

                    if (char_count[chIdx(s[left])] !=
                        numeric_limits<int>::min()) {
                        if (char_count[chIdx(s[left])] <= 0) {
                            if (char_count[chIdx(s[left])] == 0)
                                total_char_count--;
                            char_count[chIdx(s[left++])]++;
                        }
                    } else
                        left++;
                }
            } else
                right++;

            // cout << "Current window: " << s.substr(ans_edges[0], ans_edges[1]
            // - ans_edges[0]) << endl;
        }

        string ans = "";
        if (minLen != numeric_limits<int>::max())
            ans = s.substr(ans_edges[0], ans_edges[1] - ans_edges[0]);

        return ans;
    }
};