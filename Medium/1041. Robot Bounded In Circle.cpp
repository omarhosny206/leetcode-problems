// https://leetcode.com/problems/robot-bounded-in-circle/

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int currentDirection = 1;
        int xAxis = 0;
        int yAxis = 0;

        for (int i = 0; i < instructions.length(); ++i)
        {
            if (instructions[i] == 'G')
            {
                xAxis += directions[currentDirection][0];
                yAxis += directions[currentDirection][1];
            }

            else if (instructions[i] == 'L')
                currentDirection = (currentDirection + 1) % directions.size();

            else
                currentDirection = (currentDirection == 0) ? directions.size() - 1 : currentDirection - 1;
        }

        if (xAxis == 0 && yAxis == 0)
            return true;

        if (currentDirection == 1)
            return false;

        return true;
    }
};