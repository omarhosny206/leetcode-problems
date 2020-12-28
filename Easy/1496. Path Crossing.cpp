// https://leetcode.com/problems/path-crossing/

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int x = 0;
        int y = 0;
        set<pair<int, int>> locations;
        locations.insert({x, y});

        for (char c : path)
        {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'E')
                x++;
            else
                x--;

            if (locations.find({x, y}) != locations.end())
                return true;

            locations.insert({x, y});
        }

        return false;
    }
};