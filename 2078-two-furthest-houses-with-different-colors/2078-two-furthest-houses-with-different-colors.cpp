class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int firstColour = colors[0];
        int i;
        for (i = n - 1; i >= 0 && colors[i] == firstColour; i--)
            ;

        int lastColour = colors[n - 1];
        int j;
        for (j = 0; j < n && colors[j] == lastColour; j++)
            ;
        return max(i, n - 1 - j);
    }
};