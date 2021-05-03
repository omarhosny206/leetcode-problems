// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int result = 0;
        unordered_map<int, int> position;
        int mask = 0;

        position[0] = -1;

        for (int i = 0; i < s.length(); ++i)
        {
            if (isVowel(s[i]))
                mask ^= 1 << (s[i] - 'a');

            if (position.find(mask) != position.end())
                result = max(result, i - position[mask]);

            else
                position[mask] = i;
        }

        return result;
    }

    bool isVowel(char letter)
    {
        return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
    }
};