// https://leetcode.com/problems/remove-covered-intervals/

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int result = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (start <= intervals[i][0] && intervals[i][1] <= end)
                result--;

            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return result;
    }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
};