// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> result;
        unordered_set<int> nodes;
        for (vector<int> edge : edges)
        {
            nodes.insert(edge[1]);
        }

        for (int i = 0; i < n; ++i)
            if (nodes.find(i) == nodes.end())
                result.push_back(i);

        return result;
    }
};