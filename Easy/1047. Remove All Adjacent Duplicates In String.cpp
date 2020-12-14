// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution
{
public:
    string removeDuplicates(string S)
    {
        string result = "";
        stack<char> letters;

        for (char c : S)
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