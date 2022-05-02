// https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }

    static bool compare(int &first, int &second)
    {
        return isEven(first) && isOdd(second);
    }

    static bool isEven(int &num)
    {
        return num % 2 == 0;
    }

    static bool isOdd(int &num)
    {
        return num % 2 == 1;
    }
};