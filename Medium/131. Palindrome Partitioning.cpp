// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
    vector<vector<string>> result;

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> currentPath;
        dfs(s, currentPath, 0);
        return result;
    }

    void dfs(string &word, vector<string> &currentPath, int start)
    {
        if (start == word.length())
        {
            result.push_back(currentPath);
            return;
        }

        for (int i = start; i < word.length(); ++i)
        {
            if (isPalindrome(word, start, i))
            {
                currentPath.push_back(word.substr(start, i - start + 1));
                dfs(word, currentPath, i + 1);
                currentPath.pop_back();
            }
        }
    }

    bool isPalindrome(string &word, int i, int j)
    {
        while (i < j)
            if (word[i++] != word[j--])
                return false;

        return true;
    }
};