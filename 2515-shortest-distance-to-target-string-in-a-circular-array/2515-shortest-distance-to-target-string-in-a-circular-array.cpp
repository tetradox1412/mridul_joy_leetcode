class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> indexTracker;
        for (int i = 0; i < n; i++)
            if (words[i] == target)
                indexTracker.push_back(i);

        if (indexTracker.size() == 0)
            return -1;

        int mini = 101;
        for (auto x : indexTracker) {
            int minSplit = min(n - startIndex + x, startIndex + n - x);
            mini = min(mini, min(abs(startIndex - x), minSplit));
        }
        return mini;
    }
};