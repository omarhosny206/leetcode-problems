// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int result = 0;
        vector<int> freq(26);

        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (auto i : freq)
            result += abs(i);

        return result / 2;
    }
};