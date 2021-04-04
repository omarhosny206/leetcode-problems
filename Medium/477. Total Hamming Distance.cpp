// https://leetcode.com/problems/total-hamming-distance/

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            int counter = 0;

            for (int j = 0; j < nums.size(); j++)
                if ((1 << i) & nums[j])
                    counter++;

            result += (nums.size() - counter) * counter;
        }
        return result;
    }
};