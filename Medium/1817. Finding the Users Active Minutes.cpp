// https://leetcode.com/problems/finding-the-users-active-minutes/

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        vector<int> result(k);
        unordered_map<int, unordered_set<int>> UAM;

        for (vector<int> log : logs)
            UAM[log[0]].insert(log[1]);

        for (auto pair : UAM)
            ++result[pair.second.size() - 1];

        return result;
    }
};