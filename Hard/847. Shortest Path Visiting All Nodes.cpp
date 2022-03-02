// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int full_mask = (1 << (n)) - 1;
        queue<pair<int, int>> nodes;
        unordered_set<string> masks;

        for (int i = 0; i < n; i++)
        {
            nodes.push({i, 1 << i});
            masks.insert(to_string(1 << i) + " " + to_string(i));
        }

        int level = 0;

        while (!nodes.empty())
        {
            int size = nodes.size();

            while (size--)
            {
                auto [curr, mask] = nodes.front();
                nodes.pop();

                if (mask == full_mask)
                    return level;

                for (auto x : graph[curr])
                {
                    int new_mask = mask | 1 << x;
                    string check = to_string(new_mask) + " " + to_string(x);
                    if (masks.count(check))
                        continue;
                    masks.insert(check);
                    nodes.push({x, new_mask});
                }
            }

            level++;
        }

        return -1;
    }
};