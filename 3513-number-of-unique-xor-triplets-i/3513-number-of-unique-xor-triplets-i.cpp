class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3)
            return 1 << (n - 1);
        else {
            int count = 1;
            while (n != 1) {
                n = n >> 1;
                count++;
            }
            return 1 << count;
        }
    }
};