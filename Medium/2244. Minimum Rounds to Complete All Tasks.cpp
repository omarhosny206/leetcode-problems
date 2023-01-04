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
                result += (pair.second / 3) + 1;
        }

        return result;
    }
};