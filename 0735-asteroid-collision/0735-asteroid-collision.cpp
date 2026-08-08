class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (s.empty())
                s.push(asteroids[i]);
            else {
                if ((asteroids[i] > 0 && s.top() > 0) || s.top() < 0)
                    s.push(asteroids[i]);
                else {
                    while (!s.empty() && abs(s.top()) < abs(asteroids[i]) &&
                           asteroids[i] * s.top() < 0)
                        s.pop();
                    if (s.empty() || s.top() < 0)
                        s.push(asteroids[i]);
                    else if (abs(s.top()) == abs(asteroids[i]) &&
                             asteroids[i] * s.top() < 0)
                        s.pop();
                }
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        int p = ans.size();
        for (int i = 0; i < p / 2; i++)
            swap(ans[i], ans[p - i - 1]);
        return ans;
    }
};