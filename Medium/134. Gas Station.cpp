// https://leetcode.com/problems/gas-station/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int startPosition = 0;
        int totalGas = 0;
        int currentGas = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0)
            {
                startPosition = i + 1;
                currentGas = 0;
            }
        }

        return totalGas >= 0 ? startPosition : -1;
    }
};