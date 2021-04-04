// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int totalMoves = 0;
        int middle = nums.size() / 2;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
            totalMoves += abs(nums[middle] - nums[i]);

        return totalMoves;
    }
};