// https://leetcode.com/problems/make-the-string-great/

class Solution
{
public:
    string makeGood(string s)
    {

        if (s.length() < 2)
            return s;

        string result = "";
        stack<char> chars;

        for (int i = 0; i < s.length(); ++i)
        {
            if (!chars.empty() && abs((s[i] - 'a') - (chars.top() - 'a')) == 32)
                chars.pop();

            else
                chars.push(s[i]);
        }

        while (!chars.empty())
        {
            result += chars.top();
            chars.pop();
        }

        Reverse(result);
        return result;
    }

    void Reverse(string &result)
    {
        int i = 0;
        int j = result.length() - 1;

        while (i < j)
        {
            char temp = result[i];
            result[i++] = result[j];
            result[j--] = temp;
        }
    }
};