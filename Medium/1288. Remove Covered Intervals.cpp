// https://leetcode.com/problems/remove-covered-intervals/

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int result = 1;
        int i = 0;

        sort(intervals.begin(), intervals.end(), compare);

        for (int j = 0; j < intervals.size(); ++j)
        {
            if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])
                continue;

            else
            {
                i = j;
                result++;
            }
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> second)
    {
        return first[0] < second[0] || (first[0] == second[0]) && first[1] > second[1];
    }
};