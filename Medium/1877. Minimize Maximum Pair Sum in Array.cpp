// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int result = 0;
        int i = 0;
        int j = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while (i < j)
            result = max(result, nums[i++] + nums[j--]);

        return result;
    }
};