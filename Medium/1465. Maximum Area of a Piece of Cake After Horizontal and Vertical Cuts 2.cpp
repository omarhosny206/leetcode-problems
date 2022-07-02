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

        long long maxHeight = getMaxHeight(horizontalCuts, 0);
        long long maxWidth = getMaxHeight(verticalCuts, 0);

        return (maxHeight * maxWidth) % MOD;
    }

    long long getMaxHeight(vector<int> &horizontalCuts, int previousHeight)
    {
        long long result = INT_MIN;

        for (int &height : horizontalCuts)
        {
            result = max(result, (long long)(height - previousHeight));
            previousHeight = height;
        }

        return result;
    }

    long long getMaxWidth(vector<int> &verticalCuts, int previousWidth)
    {
        long long result = INT_MIN;

        for (int &width : verticalCuts)
        {
            result = max(result, (long long)(width - previousWidth));
            previousWidth = width;
        }

        return result;
    }
};