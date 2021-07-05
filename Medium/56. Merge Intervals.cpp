// https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > end)
            {
                result.push_back({start, end});
                start = intervals[i][0];
            }

            end = max(end, intervals[i][1]);
        }

        result.push_back({start, end});
        return result;
    }
};