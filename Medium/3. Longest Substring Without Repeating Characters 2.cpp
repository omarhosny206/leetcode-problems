// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> chars;
        int result = 0;
        int i = 0;
        int j = 0;

        while (i < s.length() && j < s.length())
        {
            if (chars.find(s[j]) == chars.end())
            {
                chars.insert(s[j++]);
                result = max(result, j - i);
            }

            else
                chars.erase(s[i++]);
        }

        return result;
    }
};