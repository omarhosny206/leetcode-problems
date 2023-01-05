// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int result = 1;

        sort(points.begin(), points.end(), compare);
        int firstEnd = points[0][1];

        for (vector<int> &point : points)
        {
            int secondStart = point[0];
            firstEnd = min(firstEnd, point[1]);

            if (secondStart > firstEnd)
            {
                result++;
                firstEnd = point[1];
            }
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> &second)
    {
        return (first[0] < second[0]) || (first[0] == second[0] && first[1] < second[1]);
    }
};