// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
    int result = 0;

public:
    int countVowelStrings(int n)
    {
        string vowels = "aeiou";
        string current = "";
        dfs(n, vowels, current, 0);

        return result;
    }

    void dfs(int n, string &vowels, string &current, int index)
    {
        if (n == 0)
        {
            result++;
            return;
        }

        for (int i = index; i < vowels.length(); ++i)
        {
            current += vowels[i];
            dfs(n - 1, vowels, current, i);
            current.pop_back();
        }
    }
};