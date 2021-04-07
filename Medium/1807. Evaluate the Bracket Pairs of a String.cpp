// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        string result = "";
        unordered_map<string, string> value;

        for (vector<string> key : knowledge)
            value[key[0]] = key[1];

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                string key = "";

                while (s[++i] != ')')
                    key += s[i];

                result += (value[key] != "") ? value[key] : "?";
            }

            else
                result += s[i];
        }

        return result;
    }
};