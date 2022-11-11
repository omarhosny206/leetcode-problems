// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution
{
public:
    string reverseVowels(string s)
    {
        string result = "";

        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            while (i < j && !isVowel(tolower(s[i])))
                i++;

            while (i < j && !isVowel(tolower(s[j])))
                j--;

            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }

    void swap(char &first, char &second)
    {
        char temp = first;
        first = second;
        second = temp;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};