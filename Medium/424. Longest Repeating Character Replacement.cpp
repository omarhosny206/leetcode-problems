// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxLength = INT_MIN;
        int maxLetter = INT_MIN;
        int freq[26] = {0};
        int left = 0;
        int right = 0;

        while (right < s.length())
        {
            freq[s[right] - 'A']++;
            maxLetter = max(maxLetter, freq[s[right] - 'A']);
            int windowSize = right - left + 1;

            if (windowSize - maxLetter > k)
            {
                maxLength = max(maxLength, right - left);
                freq[s[left] - 'A']--;
                left++;
            }

            right++;
        }

        return max(maxLength, right - left);
    }
};