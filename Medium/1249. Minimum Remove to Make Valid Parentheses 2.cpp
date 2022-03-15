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
            if (s[i] == '(')
                letters.push({s[i], i});

            else if (s[i] == ')')
            {
                if (!letters.empty() && letters.top().first == '(')
                {
                    valid[letters.top().second] = true;
                    valid[i] = true;
                    letters.pop();
                }
            }

            else
                valid[i] = true;
        }

        for (int i = 0; i < s.length(); ++i)
            if (valid[i])
                result += s[i];

        return result;
    }
};