// https://leetcode.com/problems/letter-case-permutation/

class Solution
{
    vector<string> result;

public:
    vector<string> letterCasePermutation(string s)
    {
        string current = s;
        dfs(s, current, 0);
        return result;
    }

    void dfs(string &s, string &current, int i)
    {
        if (i == s.length())
        {
            result.push_back(current);
            return;
        }

        if (!isdigit(s[i]))
        {
            current[i] = (isupper(s[i])) ? tolower(s[i]) : toupper(s[i]);
            dfs(s, current, i + 1);
            current[i] = s[i];
            dfs(s, current, i + 1);
        }

        else
            dfs(s, current, i + 1);
    }
};