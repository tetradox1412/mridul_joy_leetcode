class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (auto x : str) {
            if (x == '[' || x == '{' || x == '(')
                s.push(x);
            else {
                if (!s.empty() && ((x == ')' && s.top() == '(') ||
                                   (x == '}' && s.top() == '{') ||
                                   (x == ']' && s.top() == '[')))
                    s.pop();
                else
                    return false;
            }
        }
        if (s.empty())
            return true;
        else
            return false;
    }
};