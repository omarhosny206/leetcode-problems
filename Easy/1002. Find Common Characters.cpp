// https://leetcode.com/problems/find-common-characters/

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> common_chars;
        vector<int> minimum_freq(26, INT_MAX);

        for (string current : A)
        {
            vector<int> char_freq(26);

            for (char c : current)
                char_freq[c - 'a']++;

            for (int i = 0; i < 26; ++i)
                minimum_freq[i] = min(minimum_freq[i], char_freq[i]);
        }

        for (int i = 0; i < 26; ++i)
        {
            while (minimum_freq[i] > 0)
            {
                string s(1, i + 'a');
                common_chars.push_back(s);
                minimum_freq[i]--;
            }
        }

        return common_chars;
    }
};