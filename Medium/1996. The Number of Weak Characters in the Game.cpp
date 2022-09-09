// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        int result = 0;

        sort(properties.begin(), properties.end(), compare);

        int maxDefense = INT_MIN;

        for (vector<int> &property : properties)
        {
            if (maxDefense > property[1])
                result++;

            else
                maxDefense = property[1];
        }

        return result;
    }

    static bool compare(vector<int> &first, vector<int> &second)
    {
        return (first[0] > second[0]) || (first[0] == second[0] && first[1] < second[1]);
    }
};