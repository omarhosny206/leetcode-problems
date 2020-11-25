// https://leetcode.com/problems/implement-strstr/

class Solution
{
public:
    void computeLongestPrefixSum(string pattern, int patternLength, vector<int> &longestPrefixSum)
    {
        int i = 1;
        int length = 0;
        longestPrefixSum[0] = 0;

        while (i < patternLength)
        {
            if (pattern[i] == pattern[length])
            {
                length++;
                longestPrefixSum[i] = length;
                i++;
            }

            else
            {
                if (length != 0)
                    length = longestPrefixSum[length - 1];

                else
                {
                    longestPrefixSum[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string word, string pattern)
    {
        int wordLength = word.length();
        int patternLength = pattern.length();

        if (patternLength == 0)
            return 0;

        if (wordLength == 0 && patternLength == 0)
            return 0;

        if (patternLength > wordLength)
            return -1;

        vector<int> longestPrefixSum(patternLength);
        computeLongestPrefixSum(pattern, patternLength, longestPrefixSum);
        int i = 0, j = 0;

        while (i < wordLength)
        {
            if (pattern[j] == word[i])
            {
                i++;
                j++;
            }
            if (j == patternLength)
                return i - j;
            if (i < wordLength && pattern[j] != word[i])
            {
                if (j != 0)
                    j = longestPrefixSum[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};