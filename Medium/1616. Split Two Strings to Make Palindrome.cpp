// https://leetcode.com/problems/split-two-strings-to-make-palindrome/

class Solution
{
public:
    bool checkPalindromeFormation(string a, string b)
    {
        return checkPalindrome(a, b) || checkPalindrome(b, a);
    }

    bool checkPalindrome(string a, string b)
    {
        int i = 0;
        int j = a.length() - 1;
        while (i < j && a[i] == b[j])
        {
            i++;
            j--;
        }

        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

    bool isPalindrome(string s, int i, int j)
    {
        while (i < j && s[i] == s[j])
        {
            i++;
            j--;
        }

        return i >= j;
    }
};