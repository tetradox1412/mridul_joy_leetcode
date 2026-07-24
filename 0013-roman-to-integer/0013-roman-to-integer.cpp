class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int n = s.size();
        int sum = 0;
        int idx = 0;
        while (idx < n) {
            if (s[idx] == 'I' && idx != n - 1 && s[idx + 1] == 'V') {
                sum += 4;
                idx += 2;
            } else if (s[idx] == 'I' && idx != n - 1 && s[idx + 1] == 'X') {
                sum += 9;
                idx += 2;
            } else if (s[idx] == 'X' && idx != n - 1 && s[idx + 1] == 'L') {
                sum += 40;
                idx += 2;
            } else if (s[idx] == 'X' && idx != n - 1 && s[idx + 1] == 'C') {
                sum += 90;
                idx += 2;
            } else if (s[idx] == 'C' && idx != n - 1 && s[idx + 1] == 'D') {
                sum += 400;
                idx += 2;
            } else if (s[idx] == 'C' && idx != n - 1 && s[idx + 1] == 'M') {
                sum += 900;
                idx += 2;
            } else {
                sum += map[s[idx]];
                idx++;
            }
        }
        return sum;
    }
};