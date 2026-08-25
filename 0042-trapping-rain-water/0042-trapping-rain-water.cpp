class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n <= 2)
            return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = -1;
        rightMax[n - 1] = -1;

        int left = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = left;
            left = max(left, height[i]);
        }

        int right = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = right;
            right = max(right, height[i]);
        }

        int net = 0;
        for (int i = 1; i < n - 1; i++)
            net += max(0, min(leftMax[i], rightMax[i]) - height[i]);

        return net;
    }
};