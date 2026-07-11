class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> resultVec;
        int m_check = 0;
        int n_check = 0;
        while (m_check < m && n_check < n) {
            if (nums1[m_check] > nums2[n_check])
                resultVec.push_back(nums2[n_check++]);
            else if (nums1[m_check] < nums2[n_check])
                resultVec.push_back(nums1[m_check++]);
            else {
                resultVec.push_back(nums1[m_check++]);
                resultVec.push_back(nums2[n_check++]);
            }
        }
        while (m_check < m)
            resultVec.push_back(nums1[m_check++]);
        while (n_check < n)
            resultVec.push_back(nums2[n_check++]);

        for (int i = 0; i < resultVec.size(); i++)
            nums1[i] = resultVec[i];
    }
};