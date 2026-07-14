class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Find maximum weight of all packages, that will be low
        int maxWt = weights[0];
        for (auto x : weights)
            maxWt = max(maxWt, x);

        // Finding sum of weights, that will be high
        int sum = 0;
        for (auto x : weights)
            sum += x;

        // Doing binary search
        int low = maxWt;
        int high = sum;

        while (low <= high) {
            if (low == high)
                return low;

            int mid = low + (high - low) / 2;
            int midCp = mid;

            int daysTaken = 1;
            int idx = 0;
            int n = weights.size();
            while (idx < n) {
                if (midCp - weights[idx] >= 0)
                    midCp -= weights[idx++];
                else {
                    daysTaken++;
                    midCp = mid;
                }
            }

            if (daysTaken > days)
                low = mid + 1;
            else
                high = mid;
        }
        return 1;
    }
};