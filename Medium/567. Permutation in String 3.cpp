// https://leetcode.com/problems/permutation-in-string/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> firstFreq(26);
        vector<int> secondFreq(26);
        int i = 0;
        int j = 0;

        for (char &c : s1)
            firstFreq[c - 'a']++;

        while (j < s2.length())
        {
            secondFreq[s2[j] - 'a']++;

            int windowSize = j - i + 1;

            if (windowSize == s1.length())
            {
                if (firstFreq == secondFreq)
                    return true;

                secondFreq[s2[i] - 'a']--;

                i++;
            }

            j++;
        }

        return false;
    }
};