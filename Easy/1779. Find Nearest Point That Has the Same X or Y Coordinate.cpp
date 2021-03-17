// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int distance = INT_MAX;
        int position = -1;

        for (int i = 0; i < points.size(); ++i)
        {
            int a = points[i][0];
            int b = points[i][1];
            if (x == a || y == b)
            {
                if (distance > abs(x - a) + abs(y - b))
                {
                    distance = abs(x - a) + abs(y - b);
                    position = i;
                }
            }
        }

        return position;
    }
};