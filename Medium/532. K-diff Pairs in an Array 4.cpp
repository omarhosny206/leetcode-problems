// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;

        sort(nums.begin(), nums.end());

        if (k == 0)
        {
            int i = 1;

            while (i < nums.size())
            {
                if (nums[i] == nums[i - 1])
                {
                    result++;

                    while (i < nums.size() && nums[i] == nums[i - 1])
                        i++;
                }

                else
                    i++;
            }

            return result;
        }

        int i = 0;

        while (i < nums.size())
        {
            if (binarySearch(nums, i + 1, nums.size() - 1, nums[i] - k) == true)
                result++;

            if (binarySearch(nums, i + 1, nums.size() - 1, nums[i] + k) == true)
                result++;

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;

            i++;
        }

        return result;
    }

    bool binarySearch(vector<int> &nums, int i, int j, int target)
    {
        while (i <= j)
        {
            int middle = ((j - i) / 2) + i;

            if (nums[middle] == target)
                return true;

            if (nums[middle] > target)
                j = middle - 1;

            else
                i = middle + 1;
        }

        return false;
    }
};