class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int runSum = 0;
        for (auto x : gain) {
            runSum += x;
            maxi = max(maxi, runSum);
        }
        return maxi;
    }
};