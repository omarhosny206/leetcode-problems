// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int result = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < k; ++i)
            currentSum += cardPoints[i];

        result = currentSum;
        int steps = cardPoints.size() - k - 1;

        for (int j = cardPoints.size() - 1; j > steps; --j)
        {
            currentSum -= cardPoints[--k];
            currentSum += cardPoints[j];
            result = max(result, currentSum);
        }

        return result;
    }
};