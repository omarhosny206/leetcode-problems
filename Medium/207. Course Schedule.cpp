// https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses);

        for (vector<int> &prerequisite : prerequisites)
            graph[prerequisite[1]].push_back(prerequisite[0]);

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