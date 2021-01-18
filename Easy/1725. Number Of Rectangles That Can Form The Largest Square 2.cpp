// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int counter = 0;
        int maxLength = 0;
        unordered_map<int, int> freq;
        int side;

        for (vector<int> rectangle : rectangles)
        {
            side = min(rectangle[0], rectangle[1]);
            freq[side]++;
        }

        for (auto pair : freq)
        {
            if (maxLength < pair.first)
            {
                maxLength = pair.first;
                counter = pair.second;
            }
        }

        return counter;
    }
};