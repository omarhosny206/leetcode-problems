// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        string result = "";

        vector<int> freq(26);
        vector<bool> visited(26);
        stack<char> letters;

        for (char &c : s)
            freq[c - 'a']++;

        for (char &c : s)
        {
            if (visited[c - 'a'])
            {
                freq[c - 'a']--;
                continue;
            }

            while (!letters.empty() && c < letters.top() && freq[letters.top() - 'a'] > 1)
            {
                freq[letters.top() - 'a']--;
                visited[letters.top() - 'a'] = false;
                letters.pop();
            }

            letters.push(c);
            visited[c - 'a'] = true;
        }

        while (!letters.empty())
        {
            result += letters.top();
            letters.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};