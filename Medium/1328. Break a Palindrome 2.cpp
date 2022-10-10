// https://leetcode.com/problems/break-a-palindrome/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.length() < 2)
            return "";

        int i = 0;

        while (i < palindrome.length())
        {
            if (palindrome[i] != 'a')
            {
                string temp = palindrome;
                temp[i] = 'a';

                if (!isPalindrome(temp))
                    return temp;
            }

            i++;
        }

        palindrome[palindrome.length() - 1] = 'b';
        return palindrome;
    }

    bool isPalindrome(string &word)
    {
        int i = 0;
        int j = word.length() - 1;

        while (i < j)
        {
            if (word[i] != word[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};