// https://leetcode.com/problems/make-number-of-distinct-characters-equal/

class Solution
{
public:
    bool isItPossible(string word1, string word2)
    {
        vector<int> firstFreq(26);
        vector<int> secondFreq(26);
        int firstCounter = 0;
        int secondCounter = 0;

        for (char &c : word1)
            if (++firstFreq[c - 'a'] == 1)
                firstCounter++;

        for (char &c : word2)
            if (++secondFreq[c - 'a'] == 1)
                secondCounter++;

        for (int i = 0; i < firstFreq.size(); ++i)
        {
            for (int j = 0; j < secondFreq.size(); ++j)
            {
                if (firstFreq[i] > 0 && secondFreq[j] > 0)
                {
                    if (--firstFreq[i] == 0)
                        firstCounter--;

                    if (++secondFreq[i] == 1)
                        secondCounter++;

                    if (--secondFreq[j] == 0)
                        secondCounter--;

                    if (++firstFreq[j] == 1)
                        firstCounter++;

                    if (firstCounter == secondCounter)
                        return true;

                    if (++firstFreq[i] == 1)
                        firstCounter++;

                    if (--secondFreq[i] == 0)
                        secondCounter--;

                    if (++secondFreq[j] == 1)
                        secondCounter++;

                    if (--firstFreq[j] == 0)
                        firstCounter--;
                }
            }
        }

        return false;
    }
};