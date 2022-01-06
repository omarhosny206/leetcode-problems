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

        for (int i = 1; i < DURATION_LENGTH / 2; ++i)
            result += freq[i] * freq[DURATION_LENGTH - i];

        result += freq[DURATION_LENGTH / 2] * (freq[DURATION_LENGTH / 2] - 1) / 2;
        result += freq[0] * (freq[0] - 1) / 2;

        return result;
    }
};