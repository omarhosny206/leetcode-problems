// https://leetcode.com/problems/arithmetic-slices/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        int result = 0;
        int i = 0;
        int j = i + 1;

        while (i < nums.size() - 1)
        {
            int difference = nums[i + 1] - nums[i];
            j = i + 1;

            while (j < nums.size() - 1 && nums[j + 1] - nums[j] == difference)
                j++;

            int windowSize = j - i + 1;

            if (windowSize >= 3)
                result += (windowSize - 1) * (windowSize - 2) / 2;

            i = j;
        }

        return result;
    }
};