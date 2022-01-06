// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int result = 0;
        int previousDevices = 0;

        for (string &floor : bank)
        {
            int currentDevices = countDevices(floor);

            if (currentDevices > 0)
            {
                result += currentDevices * previousDevices;
                previousDevices = currentDevices;
            }
        }

        return result;
    }

    int countDevices(string &floor)
    {
        int result = 0;

        for (char &block : floor)
            if (block == '1')
                result++;

        return result;
    }
};