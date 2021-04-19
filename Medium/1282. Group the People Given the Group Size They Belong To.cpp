// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> group;

        for (int i = 0; i < groupSizes.size(); ++i)
        {
            group[groupSizes[i]].push_back(i);
            if (group[groupSizes[i]].size() == groupSizes[i])
            {
                result.push_back(group[groupSizes[i]]);
                group[groupSizes[i]].clear();
            }
        }

        return result;
    }
};