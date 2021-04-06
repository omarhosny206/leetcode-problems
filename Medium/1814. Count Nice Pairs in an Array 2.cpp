// https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        int result = 0;
        int mod = 1e9 + 7;
        unordered_map<int, int> freq;

        for (int n : nums)
        {
            result = (result + freq[n - Reverse(n)]) % mod;
            freq[n - Reverse(n)]++;
        }

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