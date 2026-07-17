class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> char_count(26, 0);
        for (auto x : text)
            char_count[x - 'a']++;

        return min(
            min(char_count['b' - 'a'], char_count['a' - 'a']),
            min(min(char_count['l' - 'a'] / 2, char_count['o' - 'a'] / 2),
                char_count['n' - 'a']));
    }
};