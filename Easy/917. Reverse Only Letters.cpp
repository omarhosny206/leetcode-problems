// https://leetcode.com/problems/reverse-only-letters/

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {

        int i = 0;
        int j = S.length() - 1;

        while (i < j)
        {
            while (i < j && !isalpha(S[i]))
                i++;
            while (i < j && !isalpha(S[j]))
                j--;
            char temp = S[i];
            S[i] = S[j];
            S[j] = temp;

            i++;
            j--;
        }

        return S;
    }
};