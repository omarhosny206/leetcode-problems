// https://leetcode.com/problems/reordered-power-of-2/

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        vector<int> freq = getFrequency(n);
        int currentPower = 1;

        for (int i = 0; i < 31; ++i)
        {
            if (freq == getFrequency(currentPower))
                return true;

            currentPower <<= 1;
        }

        return false;
    }

    vector<int> getFrequency(int n)
    {
        vector<int> result(10);

        while (n > 0)
        {
            result[n % 10]++;
            n /= 10;
        }

        return result;
    }
};