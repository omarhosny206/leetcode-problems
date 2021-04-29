// https://leetcode.com/problems/beautiful-arrangement/

class Solution
{
    int result = 0;

public:
    int countArrangement(int n)
    {
        vector<bool> visited(n);
        DFS(visited, n, 1);
        return result;
    }

    void DFS(vector<bool> &visited, int n, int index)
    {
        if (index > n)
        {
            result++;
            return;
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i] == false && (index % i == 0 || i % index == 0))
            {
                visited[i] = true;
                DFS(visited, n, index + 1);
                visited[i] = false;
            }
        }
    }
};