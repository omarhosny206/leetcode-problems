// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int result = 0;
        sort(points.begin(), points.end());

        for (int i = 1; i < points.size(); i++)
            result = max(result, points[i][0] - points[i - 1][0]);

        return result;
    }
};