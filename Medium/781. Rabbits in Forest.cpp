// https://leetcode.com/problems/rabbits-in-forest/

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int rabbits = 0;
        map<int, int> freq;

        if (answers.size() == 0)
            return rabbits;

        for (int num : answers)
        {
            if (freq[num] == 0)
            {
                rabbits += num + 1;
                freq[num] = num;
            }

            else
                freq[num]--;
        }

        return rabbits;
    }
};