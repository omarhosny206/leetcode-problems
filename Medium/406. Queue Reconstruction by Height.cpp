// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), comp);

        for (vector<int> person : people)
            queue.insert(queue.begin() + person[1], person);

        return queue;
    }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return ((a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]));
    }
};