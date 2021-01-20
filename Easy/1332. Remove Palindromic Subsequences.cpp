// https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (s.length() <= 1)
            return s.length();

        bool check = isPalindrome(s);

        return check ? 1 : 2;
    }

    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
            if (s[i++] != s[j--])
                return false;

        return true;
    }
};