
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string result = "";

        vector<int> freq(26);
        vector<bool> visited(26);
        stack<char> letters;

        for (char &c : s)
            freq[c - 'a']++;

        for (char &c : s)
        {
            freq[c - 'a']--;

            if (visited[c - 'a'])
                continue;

            while (!letters.empty() && c < letters.top() && freq[letters.top() - 'a'] > 0)
            {
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