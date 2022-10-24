// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution
{
    int result = 0;

public:
    int maxLength(vector<string> &arr)
    {
        dfs(arr, "", 0);
        return result;
    }

    void dfs(vector<string> &arr, string current, int index)
    {
        if (!hasUniqueCharacters(current))
            return;

        result = max(result, (int)current.size());

        if (index == arr.size())
            return;

        for (int i = index; i < arr.size(); ++i)
        {
            string previous = current;
            current += arr[i];
            dfs(arr, current, i + 1);
            current = previous;
        }
    }

    bool hasUniqueCharacters(string current)
    {
        vector<int> freq(26);

        for (char &c : current)
        {
            freq[c - 'a']++;

            if (freq[c - 'a'] > 1)
                return false;
        }

        return true;
    }
};