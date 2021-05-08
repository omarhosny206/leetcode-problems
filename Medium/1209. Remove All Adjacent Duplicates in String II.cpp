// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        string result = "";
        stack<pair<char, int>> letters;

        for (char c : s)
        {
            if (letters.empty() || letters.top().first != c)
                letters.push({c, 1});

            else if (letters.top().first == c)
            {
                letters.top().second++;
            }

            if (letters.top().second == k)
            {
                letters.pop();
            }
        }

        while (!letters.empty())
        {
            result.append(letters.top().second, letters.top().first);
            letters.pop();
        }

        Reverse(result);
        return result;
    }

    void Reverse(string &word)
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