// https://leetcode.com/problems/minimum-absolute-difference/

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int min_difference = INT_MAX;

        for (int i = 1; i < arr.size(); ++i)
            min_difference = min(min_difference, arr[i] - arr[i - 1]);

        for (int i = 1; i < arr.size(); ++i)
            if (arr[i] - arr[i - 1] == min_difference)
                result.push_back({arr[i - 1], arr[i]});

        return result;
    }
};