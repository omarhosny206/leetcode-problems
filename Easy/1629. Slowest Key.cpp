// https://leetcode.com/problems/slowest-key/

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        char key = keysPressed[0];
        int duration = releaseTimes[0];
        int newDuration = duration;
        for (int i = 1; i < releaseTimes.size(); ++i)
        {
            newDuration = releaseTimes[i] - releaseTimes[i - 1];

            if (newDuration > duration)
            {
                duration = newDuration;
                key = keysPressed[i];
            }

            else if (newDuration == duration)
                key = (key < keysPressed[i]) ? keysPressed[i] : key;
        }

        return key;
    }
};