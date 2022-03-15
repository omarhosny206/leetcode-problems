// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string result = "";
        stack<pair<char, int>> letters;
        vector<bool> valid(s.length());

        for (int i = 0; i < s.length(); ++i)
        {
            if (isalpha(s[i]))
                valid[i] = true;

            else if (s[i] == '(')
                letters.push({s[i], i});

            else if (!letters.empty() && letters.top().first == '(')
            {
                valid[letters.top().second] = true;
                valid[i] = true;
                letters.pop();
            }
        }

        for (int i = 0; i < s.length(); ++i)
            if (valid[i])
                result += s[i];

        return result;
    }
};