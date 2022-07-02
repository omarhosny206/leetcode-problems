// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        long long maxHeight = getMax(horizontalCuts, 0);
        long long maxWidth = getMax(verticalCuts, 0);

        return (maxHeight * maxWidth) % MOD;
    }

    long long getMax(vector<int> &values, int previousValue)
    {
        long long result = INT_MIN;

        for (int &value : values)
        {
            result = max(result, (long long)(value - previousValue));
            previousValue = value;
        }

        return result;
    }
};