// https://leetcode.com/problems/max-consecutive-ones/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int maxConsecutiveOnes = 0;
        int counter = 0;
        for (int num : nums)
        {
            if (num == 1)
                counter++;
            else
            {
                maxConsecutiveOnes = max(maxConsecutiveOnes, counter);
                counter = 0;
            }
        }

        return maxConsecutiveOnes = max(maxConsecutiveOnes, counter);
    }
};