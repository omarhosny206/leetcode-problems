// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() < 2)
            return points.size();

        sort(points.begin(), points.end(), comp);

        int answer = 1;
        int i = 0;

        for (int j = 1; j < points.size(); ++j)
        {
            int first_end = points[i][1];
            int second_start = points[j][0];
            if (first_end < second_start)
            {
                answer++;
                i = j;
            }
        }

        return answer;
    }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
};