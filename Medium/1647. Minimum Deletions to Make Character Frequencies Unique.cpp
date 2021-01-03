// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution
{
public:
    int minDeletions(string s)
    {
        int num_deletions = 0;
        vector<int> freq(26, 0);
        unordered_set<int> seen;

        for (int i = 0; i < s.length(); ++i)
            freq[s[i] - 'a']++;

        for (int i = 0; i < freq.size(); ++i)
        {
            while (seen.find(freq[i]) != seen.end())
            {
                freq[i]--;
                num_deletions++;
            }

            if (freq[i] > 0)
                seen.insert(freq[i]);
        }

        return num_deletions;
    }
};