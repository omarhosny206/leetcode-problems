// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> freq;

        for (char c : text)
        {
            if (c == 'b')
                freq[c]++;
            if (c == 'a')
                freq[c]++;
            if (c == 'l')
                freq[c]++;
            if (c == 'o')
                freq[c]++;
            if (c == 'n')
                freq[c]++;
        }

        freq['l'] /= 2;
        freq['o'] /= 2;

        string target = "balon";

        int MIN = INT_MAX;
        for (char c : target)
            MIN = min(MIN, freq[c]);

        return MIN;
    }
};