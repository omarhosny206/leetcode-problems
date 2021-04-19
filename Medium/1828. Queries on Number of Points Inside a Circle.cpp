// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> result(queries.size());
        int i = 0;
        for (vector<int> query : queries)
        {
            for (vector<int> point : points)
                if (isInside(query[0], point[0], query[1], point[1], query[2]))
                    result[i]++;
            i++;
        }

        return result;
    }

    bool isInside(int x1, int x2, int y1, int y2, int radius)
    {
        int position = pow((x1 - x2), 2) + pow((y1 - y2), 2);
        return position <= pow(radius, 2);
    }
};