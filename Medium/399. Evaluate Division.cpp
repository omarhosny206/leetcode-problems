
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> result;
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> visited;
            double value = dfs(graph, visited, queries[i][0], queries[i][1]);

            if (value == 0)
                result.push_back(-1);

            else
                result.push_back(value);
        }

        return result;
    }

    double dfs(unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited, string source, string destination)
    {
        if (graph[source].find(destination) != graph[source].end())
            return graph[source][destination];

        visited.insert(source);

        for (pair<string, int> edge : graph[source])
        {
            string currentDestination = edge.first;

            if (visited.find(currentDestination) == visited.end())
            {
                double value = dfs(graph, visited, currentDestination, destination);

                if (value != 0)
                    return graph[source][currentDestination] * value;
            }
        }

        return 0;
    }
};