// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int firstHalf = countVowels(s, 0, (s.length() / 2) - 1);
        int secondtHalf = countVowels(s, s.length() / 2, s.length() - 1);
        return firstHalf == secondtHalf;
    }

    int countVowels(string &s, int i, int j)
    {
        int counter = 0;

        while (i <= j)
        {
            char letter = tolower(s[i]);

            if (letter == 'o' || letter == 'i' || letter == 'a' || letter == 'e' || letter == 'u')
                counter++;

            i++;
        }

        return counter;
    }
};