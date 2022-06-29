// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> result(people.size(), {-1, -1});
        sort(people.begin(), people.end(), compare);

        result[people[0][1]] = people[0];

        for (int i = 1; i < people.size(); ++i)
        {
            vector<int> person = people[i];

            int j = 0;
            int counter = person[1];

            while (counter > 0)
            {
                if (person[0] <= result[j][0] || result[j][0] == -1)
                    counter--;

                j++;
            }

            while (j < people.size() && result[j][0] != -1)
                j++;

            result[j] = person;
        }

        return result;
    }

    static bool compare(vector<int> &a, vector<int> &b)
    {
        return ((a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]));
    }
};