class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26, 0);
        for (auto& x : word)
            vec[x - 'a']++;
        int sum = 0;
        int tracker = 0;
        int count = word.size();
        
        while (count > 0) {
            int max_idx = 0;
            for (int i = 1; i < 26; i++)
                max_idx = vec[i] > vec[max_idx] ? i : max_idx;
            count -= vec[max_idx];
            int char_count = vec[max_idx];
            vec[max_idx] = 0;
            sum += ((tracker++ / 8) + 1) * char_count;
        }

        return sum;
    }
};