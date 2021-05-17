// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
    vector<int> result;
    stack<int> nodes;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for (vector<int> &prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        if (!canFinish(graph, numCourses))
            return {};

        topologicalSort(graph, numCourses);

        while (!nodes.empty())
        {
            result.push_back(nodes.top());
            nodes.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    void topologicalSort(vector<vector<int>> &graph, int numCourses)
    {
        vector<bool> visited(numCourses);

        for (int i = 0; i < numCourses; ++i)
            if (!visited[i])
                DFS(graph, visited, i);
    }

    void DFS(vector<vector<int>> &graph, vector<bool> &visited, int source)
    {
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination])
                DFS(graph, visited, destination);

        nodes.push(source);
    }

    bool canFinish(vector<vector<int>> &graph, int numCourses)
    {
        vector<int> visited(graph.size());

        for (int i = 0; i < numCourses; ++i)
            if (visited[i] == 0 && hasCycle(graph, visited, i))
                return false;

        return true;
    }

    bool hasCycle(vector<vector<int>> &graph, vector<int> &visited, int source)
    {
        if (visited[source] == 1)
            return true;

        visited[source] = 1;

        for (int &destination : graph[source])
            if (visited[destination] != 2 && hasCycle(graph, visited, destination))
                return true;

        visited[source] = 2;
        return false;
    }
};