// https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            if (nums[i] % 2 > nums[j] % 2)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

            if (nums[i] % 2 == 0)
                i++;

            if (nums[j] % 2 == 1)
                j--;
        }

        return nums;
    }
};