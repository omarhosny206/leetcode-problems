// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int result = 1;

        int i = 0;
        int j = i + 1;

        sort(points.begin(), points.end(), compare);

        while (j < points.size())
        {
            int firstEnd = points[i][1];
            int secondStart = points[j][0];

            if (firstEnd < secondStart)
            {
                result++;
                i = j;
            }

            j++;
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> &second)
    {
        return first[1] < second[1];
    }
};