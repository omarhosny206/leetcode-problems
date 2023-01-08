// https://leetcode.com/problems/max-points-on-a-line/

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int result = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            int maxValue = 0;
            int samePointCounter = 1;
            unordered_map<double, int> slopeFreq;

            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePointCounter++;

                else if (points[i][0] == points[j][0])
                    slopeFreq[INT_MAX]++;

                else
                {
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    slopeFreq[slope]++;
                }
            }

            for (auto &pair : slopeFreq)
                maxValue = max(maxValue, pair.second);

            maxValue += samePointCounter;
            result = max(result, maxValue);
        }

        return result;
    }
};