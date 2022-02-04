// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int result = 0;
        stack<int> positions;

        for (int i = 0; i <= heights.size(); i++)
        {
            int currentHeight = i == heights.size() ? 0 : heights[i];

            while (!positions.empty() && currentHeight < heights[positions.top()])
            {
                int position = positions.top();
                positions.pop();

                int width = positions.empty() ? i : i - positions.top() - 1;
                int area = heights[position] * width;

                result = max(area, result);
            }

            positions.push(i);
        }

        return result;
    }
};