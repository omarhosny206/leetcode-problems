// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

class Solution
{
public:
    int numKLenSubstrNoRepeats(string S, int K)
    {
        int result = 0;

        if (K > S.size())
            return 0;

        vector<int> freq(26);
        int i = 0;
        int counter = 0;

        for (int j = 0; j < S.length(); ++j)
        {
            if (++freq[S[j] - 'a'] > 1)
                counter++;

            int windowSize = j - i + 1;

            if (windowSize == K)
            {
                if (counter == 0)
                    result++;

                if (--freq[S[i] - 'a'] > 0)
                    counter--;

                i++;
            }
        }

        return result;
    }
};