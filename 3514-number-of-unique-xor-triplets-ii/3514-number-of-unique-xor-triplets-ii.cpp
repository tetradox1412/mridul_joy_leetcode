class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> u;
        u.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                u.push_back(nums[i]);
        }

        int max_val = u.back();
        int limit = 1;
        while (limit <= max_val) {
            limit *= 2;
        }

        vector<bool> two_xor(limit, false);
        int n = u.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                two_xor[u[i] ^ u[j]] = true;
            }
        }

        vector<bool> three_xor(limit, false);
        int ans = 0;

        for (int x = 0; x < limit; x++) {
            if (two_xor[x]) {
                for (int c : u) {
                    int triplet_val = x ^ c;
                    if (!three_xor[triplet_val]) {
                        three_xor[triplet_val] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};