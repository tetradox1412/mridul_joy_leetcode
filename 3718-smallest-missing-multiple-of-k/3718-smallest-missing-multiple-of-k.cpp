class Solution {
public:
    void printArr(vector<int>& vec) {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << "\n";
    }
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> temp;
        for (int i = 0; i < nums.size(); i++)
            if (!(nums[i] % k))
                temp.insert(nums[i]);

        vector<int> tempArr;
        for (auto& x : temp)
            tempArr.push_back(x);

        sort(tempArr.begin(), tempArr.end());
        printArr(tempArr);
        int i = 0;
        for (; i < tempArr.size(); i++)
            if (tempArr[i] != k * (i + 1))
                return k * (i + 1);
        return k * (i + 1);
    }
};