// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distance;
        vector<vector<int>> answer;

        for (int i = 0; i < points.size(); i++)
            distance.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});

        while (K--)
        {
            answer.push_back(points[distance.top().second]);
            distance.pop();
        }

        return answer;
    }
};