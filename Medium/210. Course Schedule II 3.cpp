// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
    vector<int> result;
    queue<int> nodes;
    int counter = 0;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for (vector<int> &prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        if (!canFinish(graph, numCourses))
            return {};

        reverse(result.begin(), result.end());
        return result;
    }

    bool canFinish(vector<vector<int>> &graph, int numCourses)
    {
        vector<int> indegree(numCourses);

        topologicalSort(graph, indegree);

        return hasCycle(graph) == false;
    }

    bool hasCycle(vector<vector<int>> &graph)
    {
        return counter != graph.size();
    }

    void fillDegree(vector<vector<int>> &graph, vector<int> &indegree)
    {
        for (int i = 0; i < graph.size(); ++i)
            for (int &destination : graph[i])
                indegree[destination]++;
    }

    void topologicalSort(vector<vector<int>> &graph, vector<int> &indegree)
    {
        fillDegree(graph, indegree);

        for (int i = 0; i < graph.size(); ++i)
            if (indegree[i] == 0)
                nodes.push(i);

        while (!nodes.empty())
        {
            int source = nodes.front();
            nodes.pop();
            result.push_back(source);
            counter++;

            for (int &destination : graph[source])
            {
                indegree[destination]--;
                if (indegree[destination] == 0)
                    nodes.push(destination);
            }
        }
    }
};