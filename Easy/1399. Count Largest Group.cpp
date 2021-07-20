// https://leetcode.com/problems/count-largest-group/

class Solution
{
public:
    int countLargestGroup(int n)
    {
        int result = 0;
        vector<int> freq = countGroupsFrequency(n);
        int maxFreq = getMaxFreq(freq);
        result = countLargestFrequencies(freq, maxFreq);
        return result;
    }

    int countLargestFrequencies(vector<int> &freq, int maxFreq)
    {
        int result = 0;

        for (int &num : freq)
            if (num == maxFreq)
                result++;

        return result;
    }

    vector<int> countGroupsFrequency(int n)
    {
        vector<int> freq(37);

        for (int i = 1; i <= n; ++i)
            freq[countDigits(i)]++;

        return freq;
    }

    int countDigits(int number)
    {
        int result = 0;

        while (number > 0)
        {
            result += number % 10;
            number /= 10;
        }

        return result;
    }

    int getMaxFreq(vector<int> &freq)
    {
        int result = INT_MIN;

        for (int &num : freq)
            if (result < num)
                result = num;

        return result;
    }
};