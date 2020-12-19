// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> chars;
        int answer = 0;

        for (int i = 0, j = 0; j < s.length(); j++)
        {
            if (chars.find(s[j]) != chars.end())
                i = max(i, chars[s[j]]);

            answer = max(answer, j - i + 1);
            chars[s[j]] = j + 1;
        }

        return answer;
    }
};