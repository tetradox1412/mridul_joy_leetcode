class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        while (n > 0) {
            vec.push_back(n % 10);
            n /= 10;
        }
        sort(vec.begin(), vec.end());
        int product = 1;
        int high = vec.size() - 1;
        return vec[high] * vec[high - 1];
    }
};