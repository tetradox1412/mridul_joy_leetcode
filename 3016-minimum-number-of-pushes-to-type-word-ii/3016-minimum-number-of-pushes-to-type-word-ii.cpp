class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26, 0);
        for (auto& x : word)
            vec[x - 'a']++;
        sort(vec.rbegin(), vec.rend());

        int sum = 0;
        int tracker = 0;

        for (auto& char_count : vec)
            sum += ((tracker++ / 8) + 1) * char_count;

        return sum;
    }
};