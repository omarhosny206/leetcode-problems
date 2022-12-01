// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int firstCounter = 0;
        int secondCounter = 0;

        int i = 0;
        int j = s.length() / 2;

        while (j < s.length())
        {
            firstCounter += isVowel(s[i]);
            secondCounter += isVowel(s[j]);

            i++;
            j++;
        }

        return firstCounter == secondCounter;
    }

    bool isVowel(char &letter)
    {
        return letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U';
    }
};