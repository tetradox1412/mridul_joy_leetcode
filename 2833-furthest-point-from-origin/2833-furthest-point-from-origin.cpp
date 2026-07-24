class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int blanks = 0;

        for (auto x : moves) {
            if (x == 'L')
                left++;
            else if (x == 'R')
                right++;
            else
                blanks++;
        }

        return abs(left - right) + blanks;
    }
};