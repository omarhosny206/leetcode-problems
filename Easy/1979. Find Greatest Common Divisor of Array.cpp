// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int max = getMax(nums);
        int min = getMin(nums);

        return GCD(max, min);
    }

    int GCD(int first, int second)
    {
        if (second == 0)
            return first;

        return GCD(second, first % second);
    }

    int getMax(vector<int> &nums)
    {
        int result = INT_MIN;

        for (int &num : nums)
            if (result < num)
                result = num;

        return result;
    }

    int getMin(vector<int> &nums)
    {
        int result = INT_MAX;

        for (int &num : nums)
            if (result > num)
                result = num;

        return result;
    }
};