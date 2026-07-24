class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> countMoves;
        countMoves['L'] = 0;
        countMoves['R'] = 0;
        countMoves['_'] = 0;

        for (auto x : moves)
            countMoves[x]++;

        return abs(countMoves['L'] - countMoves['R']) + countMoves['_'];
    }
};