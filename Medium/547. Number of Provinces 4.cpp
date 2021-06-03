// https://leetcode.com/problems/number-of-provinces/

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int result = 0;
        vector<int> visited(isConnected.size());

        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (visited[i] == 0)
            {
                DFS(isConnected, visited, i);
                result++;
            }
        }

        return result;
    }

    void DFS(vector<vector<int>> &isConnected, vector<int> &visited, int source)
    {
        visited[source] = 1;

        for (int j = 0; j < isConnected[source].size(); ++j)
            if (isConnected[source][j] == 1 && visited[j] == 0)
                DFS(isConnected, visited, j);
    }
};