// https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/

class Solution
{
public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, unordered_set<int>> graph(n);
        vector<int> nodesWithOddEdges;

        for (vector<int> &edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        for (auto &pair : graph)
            if (pair.second.size() % 2 != 0)
                nodesWithOddEdges.push_back(pair.first);

        if (nodesWithOddEdges.size() > 4 || nodesWithOddEdges.size() % 2 != 0)
            return false;

        if (nodesWithOddEdges.size() == 0)
            return true;

        if (nodesWithOddEdges.size() == 2)
        {
            int first = nodesWithOddEdges[0];
            int second = nodesWithOddEdges[1];

            if (graph[first].find(second) == graph[first].end())
                return true;

            for (int i = 1; i <= n; ++i)
                if (i != first && i != second && graph[first].find(i) == graph[first].end() && graph[second].find(i) == graph[second].end())
                    return true;

            return false;
        }

        int first = nodesWithOddEdges[0];
        int second = nodesWithOddEdges[1];
        int third = nodesWithOddEdges[2];
        int fourth = nodesWithOddEdges[3];

        return (graph[first].find(second) == graph[first].end() && graph[third].find(fourth) == graph[third].end()) ||
               (graph[first].find(third) == graph[first].end() && graph[second].find(fourth) == graph[second].end()) ||
               (graph[first].find(fourth) == graph[first].end() && graph[second].find(third) == graph[second].end());
    }
};