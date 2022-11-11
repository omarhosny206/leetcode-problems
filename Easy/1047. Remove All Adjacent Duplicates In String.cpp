// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string result = "";
        stack<char> letters;

        for (char &c : s)
        {
            if (letters.empty() || c != letters.top())
                letters.push(c);

            else if (c == letters.top())
                letters.pop();
        }

        while (!letters.empty())
        {
            result += letters.top();
            letters.pop();
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