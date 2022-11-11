// https://leetcode.com/problems/make-the-string-great/

// https://leetcode.com/problems/make-the-string-great/

class Solution
{
public:
    string makeGood(string s)
    {
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

        reverse(result);

        return result;
    }

    void reverse(string &word)
    {
        int i = 0;
        int j = word.length() - 1;

        while (i < j)
        {
            char temp = word[i];
            word[i++] = word[j];
            word[j--] = temp;
        }
    }
};