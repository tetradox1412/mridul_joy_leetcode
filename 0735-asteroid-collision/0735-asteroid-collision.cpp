class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {
                if (-asteroids[i] > s.top()) {
                    s.pop();
                    continue;
                } else if (-asteroids[i] == s.top())
                    s.pop();

                destroyed = true;
                break;
            }
            if (!destroyed)
                s.push(asteroids[i]);
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