// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution
{
    int result = 0;

public:
    int maxLength(vector<string> &arr)
    {
        dfs(arr, {}, 0, "");
        return result;
    }

    void dfs(vector<string> &arr, vector<int> freq, int i, string current)
    {
        if (!isOk(freq))
            return;

        result = max(result, (int)current.length());

        if (i == arr.size())
            return;

        for (int j = i; j < arr.size(); ++j)
        {
            string previous = current;
            current += arr[j];

            freq = countFreq(current);

            dfs(arr, freq, j + 1, current);
            current = previous;
        }
    }

    vector<int> countFreq(string current)
    {
        vector<int> freq(26);

        for (char &c : current)
            freq[c - 'a']++;

        return freq;
    }

    bool isOk(vector<int> freq)
    {
        for (int i = 0; i < freq.size(); ++i)
            if (freq[i] > 1)
                return false;

        return true;
    }
};