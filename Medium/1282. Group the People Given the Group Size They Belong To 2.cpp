// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> group;

        for (int i = 0; i < groupSizes.size(); ++i)
            group[groupSizes[i]].push_back(i);

        for (auto pair : group)
        {
            int size = pair.first;
            vector<int> persons = pair.second;
            vector<int> current;

            for (int i = 0; i < persons.size(); ++i)
            {
                current.push_back(persons[i]);
                if (current.size() == size)
                {
                    result.push_back(current);
                    current.clear();
                }
            }
        }

        return result;
    }
};