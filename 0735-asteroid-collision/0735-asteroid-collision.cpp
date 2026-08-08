class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while (!s.empty() && s.back() > 0 && asteroids[i] < 0) {
                if (-asteroids[i] > s.back()) {
                    s.pop_back();
                    continue;
                } else if (-asteroids[i] == s.back())
                    s.pop_back();

                destroyed = true;
                break;
            }
            if (!destroyed)
                s.push_back(asteroids[i]);
        }
        return s;
    }
};