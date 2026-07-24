class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // 'L' -> idx 0. 'R' -> idx 1. '_' -> idx 2
        vector<int> countMoves(3, 0);

        for (auto x : moves) {
            if (x == 'L')
                countMoves[0]++;
            else if (x == 'R')
                countMoves[1]++;
            else
                countMoves[2]++;
        }

        return abs(countMoves[0] - countMoves[1]) + countMoves[2];
    }
};