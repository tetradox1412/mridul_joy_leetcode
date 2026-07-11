class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int> s;
    int size = heights.size();

    // Finding previous 1st smaller elements
    vector<int> prevSmall(size, -1);
    for (int idx = size - 1; idx >= 0; idx--)
    {
        while (!s.empty() && heights[idx] < heights[s.top()])
        {
            prevSmall[s.top()] = idx;
            s.pop();
        }
        s.push(idx);
    }

    // Emptying stack
    while (!s.empty())
        s.pop();

    // Finding next 1st smaller elements
    vector<int> nextSmall(size, size);
    for (int idx = 0; idx < size; idx++)
    {
        while (!s.empty() && heights[idx] < heights[s.top()])
        {
            nextSmall[s.top()] = idx;
            s.pop();
        }
        s.push(idx);
    }

    // Finding all possible maximum histogram's area
    vector<int> maxAreas(size, 0);
    for (int idx = 0; idx < size; idx++)
        maxAreas[idx] = (nextSmall[idx] - prevSmall[idx] - 1) * heights[idx];

    // Find the maximum out of this
    int max = maxAreas[0];
    for (int i = 1; i < size; i++)
        if (maxAreas[i] > max)
            max = maxAreas[i];

    return max;
    }
};