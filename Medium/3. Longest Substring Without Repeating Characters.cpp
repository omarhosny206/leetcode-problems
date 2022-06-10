// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        unordered_map<char, int> seen;
        int i = 0;

        for (int j = 0; j < s.length(); j++)
        {
            if (seen.find(s[j]) != seen.end())
                i = max(i, seen[s[j]]);

            seen[s[j]] = j + 1;
            result = max(result, j - i + 1);
        }

        return result;
    }
};