// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int &task : tasks)
            freq[task]++;

        for (auto &pair : freq)
        {
            if (pair.second == 1)
                return -1;

            else if (pair.second % 3 == 0)
                result += pair.second / 3;

            else
            {
                int temp = pair.second;

                while (temp % 3 != 0)
                    temp -= 2;

                result += (temp) / 3;
                result += (pair.second - temp) / 2;
            }
        }

        return result;
    }
};