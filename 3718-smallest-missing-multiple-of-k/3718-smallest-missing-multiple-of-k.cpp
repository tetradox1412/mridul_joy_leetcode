class Solution {
public:
    void printArr(vector<int>& vec) {
        for (auto& x : vec)
            cout << x << " ";
        cout << "\n";
    }

    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> compare(n);
        int i = 1;
        for (auto& x : compare)
            x = k * i++;

        for (auto& x : nums)
            if (!(x % k) && (x / k) <= n)
                compare[(x / k) - 1] = -1;

        for (auto& x : compare)
            if (x != -1)
                return x;
        return k * (n + 1);
    }
};