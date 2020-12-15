// https://leetcode.com/problems/longest-palindrome/

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        int length = 0;
        bool oddIsFound = false;

        for (char c : s)
            freq[c]++;

        for (auto pair : freq)
        {
            if (pair.second % 2 != 0)
            {
                length--;
                oddIsFound = true;
            }

            length += pair.second;
        }

        return oddIsFound == true ? ++length : length;
    }
};