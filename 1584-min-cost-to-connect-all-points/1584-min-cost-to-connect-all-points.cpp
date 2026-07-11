class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        int ans = 0;
        vector<int> mstSet(size, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push(make_pair(0, 0));
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (!mstSet[p.second]) {
                mstSet[p.second] = true;
                ans += p.first;
                for (int i = 0; i < size; i++) {
                    if (i != p.second) {
                        if (!mstSet[i])
                            pq.push(make_pair(dist(points[p.second], points[i]),
                                              i));
                    }
                }
            }
        }
        return ans;
    }
};