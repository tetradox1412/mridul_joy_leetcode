class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return arr;
        vector<pair<int, int>> tracker;
        for (int i = 0; i < n; i++)
            tracker.push_back({arr[i], i});

        sort(tracker.begin(), tracker.end());

        int rank = 1;
        arr[tracker[0].second] = rank;
        int idx = 1;
        while (idx < n)
            arr[tracker[idx++].second] =
                tracker[idx].first != tracker[idx - 1].first ? ++rank : rank;

        return arr;
    }
};