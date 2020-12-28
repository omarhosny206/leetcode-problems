// https://leetcode.com/problems/path-crossing/

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int x = 0;
        int y = 0;
        set<string> locations;
        locations.insert(to_string(x) + "." + to_string(y));

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

            if (locations.find(to_string(x) + "." + to_string(y)) != locations.end())
                return true;

            locations.insert(to_string(x) + "." + to_string(y));
        }

        return false;
    }
};