class Solution {
public:
    int stn(string s) {
        int num = 0;
        bool negFlag;
        negFlag = (s[0] == '-');
        if (negFlag) {
            for (int i = 1; i < s.size(); i++)
                num = num * 10 + (s[i] - '0');
            return -1 * num;
        } else {
            for (int i = 0; i < s.size(); i++)
                num = num * 10 + (s[i] - '0');
            return num;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_set<string> op = {"+", "-", "*", "/"};
        for (int i = 0; i < tokens.size(); i++) {
            if (op.contains(tokens[i])) {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (tokens[i] == "+")
                    s.push(a + b);
                else if (tokens[i] == "-")
                    s.push(b - a);
                else if (tokens[i] == "*")
                    s.push(b * a);
                else
                    s.push(b / a);
            } else
                s.push(stn(tokens[i]));
        }
        return s.top();
    }
};