// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        string result = "";
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            while (i < j && vowels.find(tolower(s[i])) == vowels.end())
                i++;
            while (i < j && vowels.find(tolower(s[j])) == vowels.end())
                j--;

            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }

        return s;
    }
};