// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> seen(rooms.size(), false);
        seen[0] = true;

        stack<int> keys;
        keys.push(0);

        while (!keys.empty())
        {
            int currentKey = keys.top();
            keys.pop();
            for (int key : rooms[currentKey])
            {
                if (!seen[key])
                {
                    seen[key] = true;
                    keys.push(key);
                }
            }
        }

        for (bool visited : seen)
            if (!visited)
                return false;

        return true;
    }
};