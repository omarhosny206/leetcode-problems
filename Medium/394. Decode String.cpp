// https://leetcode.com/problems/decode-string/submissions/

class Solution
{
    string DFS(string &s, int &i)
    {
        string result = "";
        while (i < s.size() && s[i] != ']')
        {

            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.size() && isdigit(s[i]))
                    k = k * 10 + (s[i++] - '0');

                i++;

                string requiredChars = DFS(s, i);

                while (k--)
                    result += requiredChars;

                i++;
            }

            else
                result += s[i++];
        }

        return result;
    }

public:
    string decodeString(string s)
    {
        int i = 0;
        return DFS(s, i);
    }
};
