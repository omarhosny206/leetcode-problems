// https://leetcode.com/problems/the-k-strongest-values-in-an-array/

class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        vector<int> result;
        priority_queue<pair<int, int>> maxHeap;

        sort(arr.begin(), arr.end());
        int median = arr[(arr.size() - 1) / 2];

        for (auto num : arr)
            maxHeap.push({abs(num - median), num});

        while (k--)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};