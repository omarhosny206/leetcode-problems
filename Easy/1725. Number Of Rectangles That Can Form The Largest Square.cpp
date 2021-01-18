// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int counter = 0;
        int side;
        int maxLength = 0;

        for (vector<int> rectangle : rectangles)
        {
            side = min(rectangle[0], rectangle[1]);

            if (side > maxLength)
            {
                maxLength = side;
                counter = 1;
            }

            else if (side == maxLength)
                counter++;
        }

        return counter;
    }
};