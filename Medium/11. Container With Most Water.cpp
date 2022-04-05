
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            int area = calculateRectangleArea(min(height[i], height[j]), j - i);

            result = max(result, area);

            if (height[i] > height[j])
                j--;

            else
                i++;
        }

        return result;
    }

    int calculateRectangleArea(int length, int width)
    {
        return length * width;
    }
};