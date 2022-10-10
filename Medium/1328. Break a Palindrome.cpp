// https://leetcode.com/problems/break-a-palindrome/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.length() < 2)
            return "";

        int i = 0;
        int j = palindrome.length() - 1;

        while (i < j)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }

            i++;
            j--;
        }

        palindrome[palindrome.length() - 1] = 'b';
        return palindrome;
    }
};