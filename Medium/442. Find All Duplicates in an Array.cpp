// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            nums[abs(nums[i]) - 1] *= -1;

            if (nums[abs(nums[i]) - 1] > 0)
                result.push_back(abs(nums[i]));
        }

        return result;
    }
};