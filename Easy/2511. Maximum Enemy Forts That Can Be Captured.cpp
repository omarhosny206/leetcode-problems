// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/

class Solution
{
private:
    int result = 0;

public:
    int captureForts(vector<int> &forts)
    {
        count(forts);

        reverse(forts.begin(), forts.end());

        count(forts);

        return result;
    }

    void count(vector<int> &forts)
    {
        for (int i = 0; i < forts.size(); ++i)
        {
            if (forts[i] == 1)
            {
                int counter = 0;
                int j = i + 1;

                while (j < forts.size() && forts[j] == 0)
                {
                    counter++;
                    j++;
                }

                if (j < forts.size() && forts[j] == -1 && counter > 0)
                    result = max(result, counter);
            }
        }
    }
};