// https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int result = 0;
        int i = 0;
        int j = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                result++;
                i++;
                j--;
            }

            else if (nums[i] + nums[j] > k)
                j--;

            else
                i++;
        }

        return result;
    }
};