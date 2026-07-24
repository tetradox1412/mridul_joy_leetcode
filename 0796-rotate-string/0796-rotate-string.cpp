class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size())
            return false;
        else {
            for (int i = 0; i < n; i++) {
                char character = s[n - 1];
                s.pop_back();
                s = character + s;
                if (s == goal)
                    return true;
            }
            return false;
        }
    }
};