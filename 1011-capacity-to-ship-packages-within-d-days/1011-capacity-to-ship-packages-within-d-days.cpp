class Solution {
public:
    int findingRightCounter(vector<int>& weights, int days, int lowWt,
                            int highWt) {

        int n = weights.size();
        while (lowWt < highWt) {
            if (lowWt + 1 == highWt)
                return highWt;

            int midWt = lowWt + (highWt - lowWt) / 2;
            int daysTaken = 1;
            int i = 0;
            while (i < n) {
                if (midWt - weights[i] >= 0)
                    midWt -= weights[i++];
                else {
                    daysTaken++;
                    midWt = lowWt + (highWt - lowWt) / 2;
                }
            }
            midWt = lowWt + (highWt - lowWt) / 2;
            if (daysTaken > days)
                lowWt = midWt;
            else
                highWt = midWt;
        }
        return -1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = weights[0];
        for (auto x : weights)
            maxWeight = max(maxWeight, x);

        int tempMax = maxWeight;
        int daysTaken = 1;
        int i = 0;
        while (i < n) {
            if (tempMax - weights[i] >= 0)
                tempMax -= weights[i++];
            else {
                daysTaken++;
                tempMax = maxWeight;
            }
        }
        if (daysTaken <= days)
            return maxWeight;
        else {
            int counter = 1;
            tempMax = maxWeight + counter;
            while (true) {
                int daysTaken = 1;
                int i = 0;
                while (i < n) {
                    if (tempMax - weights[i] >= 0)
                        tempMax -= weights[i++];
                    else {
                        daysTaken++;
                        tempMax = maxWeight + counter;
                    }
                }
                if (daysTaken > days) {
                    counter = counter << 1;
                    tempMax = maxWeight + counter;
                } else
                    return findingRightCounter(weights, days,
                                               maxWeight + (counter >> 1),
                                               maxWeight + counter);
            }
        }
    }
};