// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            int oddPalindromeLength = Expand(s, i, i);
            int evenPalindromeLength = Expand(s, i, i + 1);
            int length = max(oddPalindromeLength, evenPalindromeLength);

            if (length > end - start + 1)
            {
                start = i - ((length - 1) / 2);
                end = i + (length / 2);
            }
        }

        return s.substr(start, end - start + 1);
    }

    int Expand(string &s, int i, int j)
    {
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }

        return j - i - 1;
    }
};