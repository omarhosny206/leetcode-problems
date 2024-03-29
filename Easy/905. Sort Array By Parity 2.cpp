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
            if (isOdd(nums[i]) && isEven(nums[j]))
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

            if (isEven(nums[i]))
                i++;

            if (isOdd(nums[j]))
                j--;
        }

        return nums;
    }

    bool isEven(int &num)
    {
        return num % 2 == 0;
    }

    bool isOdd(int &num)
    {
        return num % 2 == 1;
    }
};