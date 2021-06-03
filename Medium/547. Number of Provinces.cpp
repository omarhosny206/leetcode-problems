// https://leetcode.com/problems/number-of-provinces/

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int result = isConnected.size();
        vector<int> parent(isConnected.size(), -1);

        for (int i = 0; i < isConnected.size(); ++i)
        {
            for (int j = 0; j < isConnected.size(); ++j)
            {

                if (isConnected[i][j] == 1 && i != j)
                {
                    int sourceParent = Find(parent, i);
                    int destinationParent = Find(parent, j);

                    if (sourceParent != destinationParent)
                    {
                        Union(parent, sourceParent, destinationParent);
                        result--;
                    }
                }
            }
        }

        return result;
    }

    int Find(vector<int> &parent, int &source)
    {
        if (parent[source] == -1)
            return source;

        return Find(parent, parent[source]);
    }

    void Union(vector<int> &parent, int &source, int &destination)
    {
        parent[destination] = source;
        return;
    }
};