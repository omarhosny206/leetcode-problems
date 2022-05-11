// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
    int result = 0;

public:
    int countVowelStrings(int n)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        dfs(n, vowels, ' ');

        return result;
    }

    void dfs(int n, vector<char> &vowels, char previousVowel)
    {
        if (n == 0)
        {
            result++;
            return;
        }

        for (char &vowel : vowels)
            if (vowel >= previousVowel)
                dfs(n - 1, vowels, vowel);
    }
};