class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int count = 0;

        for (auto x : word) {
            if (x >= 'a')
                lower[x - 'a'] = 1;
            else
                upper[x - 'A'] = 1;
        }

        for (int i = 0; i < 26; i++)
            if (lower[i] == 1 && upper[i] == 1)
                count++;

        return count;
    }
};