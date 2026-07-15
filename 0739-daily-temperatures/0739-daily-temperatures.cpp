class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();

        vector<int> answer(n, 0);
        st.push(make_pair(temperatures[n - 1], n - 1));
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i])
                st.pop();

            if (!st.empty())
                answer[i] = st.top().second - i;
            st.push(make_pair(temperatures[i], i));
        }

        return answer;
    }
};