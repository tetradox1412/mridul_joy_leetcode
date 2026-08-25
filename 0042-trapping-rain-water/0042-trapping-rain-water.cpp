class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n <= 2)
            return 0;

        int left = 0, right = n - 1, net = 0, leftMax = height[0],
            rightMax = height[n - 1];

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax)
                    leftMax = height[left++];
                else
                    net += leftMax - height[left++];
            } else {
                if (height[right] > rightMax)
                    rightMax = height[right--];
                else
                    net += rightMax - height[right--];
            }
        }

        return net;
    }
};