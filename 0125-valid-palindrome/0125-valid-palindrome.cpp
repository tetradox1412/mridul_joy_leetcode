class Solution {
public:
    bool isPalindrome(string s) {
        bool isPal = true;
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {

            if (!((s[start] >= 'a' && s[start] <= 'z') ||
                  (s[start] >= 'A' && s[start] <= 'Z') ||
                  (s[start] - '0' <= 9 && s[start] - '0' >= 0))) {
                start++;
                continue;
            }

            if (!((s[end] >= 'a' && s[end] <= 'z') ||
                  (s[end] >= 'A' && s[end] <= 'Z') ||
                  (s[end] - '0' <= 9 && s[end] - '0' >= 0))) {
                end--;
                continue;
            }

            if (s[start] >= 'A' && s[start] <= 'Z')
                s[start] = s[start] - 'A' + 'a';

            if (s[end] >= 'A' && s[end] <= 'Z')
                s[end] = s[end] - 'A' + 'a';

            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                isPal = false;
                break;
            }
        }
        return isPal;
    }
};
