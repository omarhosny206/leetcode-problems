// https://leetcode.com/problems/find-center-of-star-graph/

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> freq;
        for (vector<int> edge : edges)
        {
            freq[edge[0]]++;
            freq[edge[1]]++;
        }

        for (auto pair : freq)
            if (pair.second == edges.size())
                return pair.first;

        return -1;
    }
};