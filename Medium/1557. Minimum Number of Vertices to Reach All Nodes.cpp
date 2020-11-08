// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> result;
        vector<int> nodes(n);
        for (const auto &edge : edges)
        {
            nodes[edge[1]] = 1;
        }

        for (int i = 0; i < n; ++i)
            if (nodes[i] == 0)
                result.push_back(i);

        return result;
    }
};