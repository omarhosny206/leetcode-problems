// https://leetcode.com/problems/next-permutation/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0)
        {
            int j = nums.size() - 1;

            while (nums[j] <= nums[i])
                j--;

            swap(nums, i, j);
        }

        reverse(nums, i + 1, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
    }

    void swap(vector<int> &nums, int i, int j)
    {

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};