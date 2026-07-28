class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        vector<int> vec(26, 0);
        for (auto& x : s)
            vec[x - 'a']++;

        char odd_char = 'a';
        int odd_char_present = 0;
        for (int i = 0; i < 26; i++)
            if (vec[i] % 2) {
                odd_char = 'a' + i;
                odd_char_present = 1;
                break;
            }

        vector<char> ans(n);
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            while (vec[i] > 1) {
                vec[i] -= 2;
                ans[idx] = 'a' + i;
                ans[n - 1 - idx] = 'a' + i;
                idx++;
            }
        }

        for (int i = idx; i <= n - 1 - idx && odd_char_present; i++)
            ans[i] = odd_char;

        string answer;
        for (auto& x : ans)
            answer += x;
        return answer;
    }
};