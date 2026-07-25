class Solution {
public:
    int maxProduct(int n) {
        vector<int> integers(10, 0);
        while (n > 0) {
            integers[n % 10]++;
            n /= 10;
        }

        for (auto x : integers)
            cout << x << " ";
        cout << endl;

        int product = 1;
        int count = 0;
        int idx = 9;
        while (idx >= 0 && count != 2) {
            while (integers[idx] > 0 && count != 2) {
                product *= idx;
                count++;
                integers[idx]--;
            }
            idx--;
        }
        return product;
    }
};