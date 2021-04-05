// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int counter = 0;
        int intervalEnd = INT_MIN;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= intervalEnd)
                intervalEnd = intervals[i][1];
            else
            {
                counter++;
                intervalEnd = min(intervalEnd, intervals[i][1]);
            }
        }

        return counter;
    }
};