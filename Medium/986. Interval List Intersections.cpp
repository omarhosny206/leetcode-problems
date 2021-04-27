// https://leetcode.com/problems/interval-list-intersections/

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        if (firstList.size() == 0 || secondList.size() == 0)
            return {};

        vector<vector<int>> result;
        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size())
        {
            int intersectionStart = max(firstList[i][0], secondList[j][0]);
            int intersectionEnd = min(firstList[i][1], secondList[j][1]);

            if (intersectionStart <= intersectionEnd)
                result.push_back({intersectionStart, intersectionEnd});

            if (firstList[i][1] < secondList[j][1])
                ++i;

            else
                ++j;
        }

        return result;
    }
};