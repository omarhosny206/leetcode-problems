// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int result = 0;
        int DURATION_LENGTH = 60;
        vector<int> freq(DURATION_LENGTH);

        for (int i = 0; i < time.size(); ++i)
            freq[time[i] % DURATION_LENGTH]++;

        for (int i = 0; i <= DURATION_LENGTH / 2; ++i)
        {
            if (i == 0 || i == DURATION_LENGTH / 2)
                result += freq[i] * (freq[i] - 1) / 2;

            else
                result += freq[i] * freq[DURATION_LENGTH - i];
        }

        return result;
    }
};