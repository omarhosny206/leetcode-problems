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
        return first % 2 < second % 2;
    }
};