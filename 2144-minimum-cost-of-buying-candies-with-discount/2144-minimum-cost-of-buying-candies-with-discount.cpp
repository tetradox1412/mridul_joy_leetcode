class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 2)
            return cost[0] + cost[1];
        int sum = 0;
        sort(cost.begin(), cost.end());
        for (auto x : cost)
            sum += x;
        for (int i = n - 3; i >= 0; i -= 3)
            sum -= cost[i];
        return sum;
    }
};