// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        Reverse(nums, 0, nums.size() - 1);
        Reverse(nums, 0, k - 1);
        Reverse(nums, k, nums.size() - 1);
    }

    void Reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
    }
};