class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long double)m * k > n)
            return -1;

        // Getting binary search range
        int minDays = bloomDay[0];
        int maxDays = bloomDay[0];
        for (auto x : bloomDay) {
            minDays = min(minDays, x);
            maxDays = max(maxDays, x);
        }

        // Finding if each day possible for question condition
        while (minDays <= maxDays) {
            if (minDays == maxDays)
                return maxDays;

            vector<int> hasFlowerBloomed(n, 0);
            int currDays = minDays + (maxDays - minDays) / 2;

            for (int i = 0; i < n; i++)
                if (bloomDay[i] <= currDays)
                    hasFlowerBloomed[i] = 1;

            int counter = 0;
            int bouquetsFormed = 0;
            for (int i = 0; i < n; i++) {
                if (hasFlowerBloomed[i] == 1)
                    counter++;
                else {
                    bouquetsFormed += counter / k;
                    counter = 0;
                }
            }
            bouquetsFormed += counter / k;

            if (bouquetsFormed < m)
                minDays = currDays + 1;
            else
                maxDays = currDays;
        }
        return -1;
    }
};