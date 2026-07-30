class Solution {
public:
    int minimumPushes(string word) {
        vector<char> vec(26, 0);
        for (auto& x : word)
            vec[x - 'a']++;
        int count = 0;
        int sum = 0;
        for (int i = 26; i >= 1; i--) {
            for (int j = 0; j < 26; j++)
                if (vec[j] == i)
                    sum += (count++ / 8) + 1;
        }
        return sum;
    }
};