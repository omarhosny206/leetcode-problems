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
        if (i > s.length())
            return;

        result.push_back(current);

        for (int j = i; j < s.length(); ++j)
        {
            if (!isdigit(s[j]))
            {
                current[j] = (isupper(s[j])) ? tolower(s[j]) : toupper(s[j]);
                dfs(s, current, j + 1);
                current[j] = s[j];
            }
        }
    }
};