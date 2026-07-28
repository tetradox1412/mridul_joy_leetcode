class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        vector<int> vec(26, 0);
        for (auto& x : s)
            vec[x - 'a']++;

        char odd_char;
        int odd_char_present = 0;
        for (int i = 0; i < 26; i++)
            if (vec[i] % 2) {
                odd_char = 'a' + i;
                odd_char_present = 1;
                break;
            }

        int idx = 0;
        for (int i = 0; i < 26; i++) {
            while (vec[i] > 1) {
                vec[i] -= 2;
                s[idx] = 'a' + i;
                s[n - 1 - idx] = 'a' + i;
                idx++;
            }
        }

        if (odd_char_present)
            s[idx] = odd_char;

        return s;
    }
};