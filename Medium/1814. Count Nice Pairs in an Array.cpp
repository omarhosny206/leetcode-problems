// https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        long result = 0;
        int mod = 1e9 + 7;
        unordered_map<int, long> freq;

        for (int n : nums)
            freq[n - Reverse(n)]++;

        for (auto pair : freq)
            result = (result + (pair.second * (pair.second - 1)) / 2) % mod;

        return result;
    }

    int Reverse(int number)
    {
        int result = 0;

        while (number > 0)
        {
            result = result * 10 + number % 10;
            number /= 10;
        }

        return result;
    }
};