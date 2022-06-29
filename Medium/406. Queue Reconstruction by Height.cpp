
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), compare);

        for (vector<int> &person : people)
            result.insert(result.begin() + person[1], person);

        return result;
    }

    static bool compare(vector<int> &a, vector<int> &b)
    {
        return ((a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]));
    }
};