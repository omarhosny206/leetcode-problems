// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;

        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size(); ++j)
                min_heap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});

        while (!min_heap.empty() && k--)
        {
            auto pair = min_heap.top();
            min_heap.pop();
            result.push_back({pair.second.first, pair.second.second});
        }

        return result;
    }
};