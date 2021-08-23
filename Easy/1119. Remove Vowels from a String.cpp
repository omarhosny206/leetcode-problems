// https://leetcode.com/problems/remove-vowels-from-a-string/

class Solution
{
public:
    string removeVowels(string S)
    {
        string result = "";

        for (char &c : S)
            if (!isVowel(c))
                result += c;

        return result;
    }

    bool isVowel(char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};