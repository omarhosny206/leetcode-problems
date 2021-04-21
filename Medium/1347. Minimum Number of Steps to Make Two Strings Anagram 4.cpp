// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int result = 0;
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (auto pair : freq)
            result += abs(pair.second);

        return result / 2;
    }
};