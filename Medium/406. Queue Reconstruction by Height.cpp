// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> result(people.size(), {-1, -1});
        sort(people.begin(), people.end(), compare);

        for (vector<int> &person : people)
        {
            int i = 0;
            int counter = person[1];

            while (counter > 0)
            {
                if (person[0] <= result[i][0] || result[i][0] == -1)
                    counter--;

                i++;
            }

            while (i < people.size() && result[i][0] != -1)
                i++;

            result[i] = person;
        }

        return result;
    }

    static bool compare(vector<int> &a, vector<int> &b)
    {
        return ((a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]));
    }
};