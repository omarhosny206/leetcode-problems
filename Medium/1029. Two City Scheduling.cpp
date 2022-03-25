
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int result = 0;
        int i = 0;

        sort(costs.begin(), costs.end(), compare);

        while (i < costs.size() / 2)
        {
            result += costs[i][0];
            i++;
        }

        while (i < costs.size())
        {
            result += costs[i][1];
            i++;
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> &second)
    {
        int firstDifference = first[0] - first[1];
        int secondDifference = second[0] - second[1];

        return firstDifference < secondDifference;
    }
};