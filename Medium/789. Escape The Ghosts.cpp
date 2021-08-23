// https://leetcode.com/problems/escape-the-ghosts/

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int distance = abs(target[1] - 0) + abs(target[0] - 0);

        for (vector<int> &ghost : ghosts)
        {
            int ghostDistance = abs(target[1] - ghost[1]) + abs(target[0] - ghost[0]);

            if (distance >= ghostDistance)
                return false;
        }

        return true;
    }
};