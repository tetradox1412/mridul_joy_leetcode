class Solution {
public:
    int searchInRange(vector<int>& piles, int high, int h) {
        int n = piles.size();
        int low = high >> 1;
        int k;
        while (low < high) {
            if (low + 1 == high)
                return high;

            k = low + (high - low) / 2;
            int hour = 0;
            for (int i = 0; i < n; i++)
                hour += ceil((double)piles[i] / k);

            if (hour > h)
                low = k;
            else
                high = k;
        }
        return -1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // if (n == 1)
        //     return ceil((double)piles[0] / h);
        int k = 1;
        bool enough_k = true;
        while (true) {
            long double hour = 0;
            for (int i = 0; i < n; i++)
                hour += ceil((double)piles[i] / k);

            if (hour > h)
                k = k << 1;
            else
                return searchInRange(piles, k, h);
        }
    }
};