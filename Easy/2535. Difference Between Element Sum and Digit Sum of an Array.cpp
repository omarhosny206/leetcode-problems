// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int sum = getSum(nums);
        int digitSum = getDigitSum(nums);

        return abs(sum - digitSum);
    }

    int getDigitSum(vector<int> &nums)
    {
        int result = 0;

        for (int num : nums)
        {
            while (num > 0)
            {
                result += num % 10;
                num /= 10;
            }
        }

        return result;
    }

    int getSum(vector<int> &nums)
    {
        int result = 0;

        for (int &num : nums)
            result += num;

        return result;
    }
};