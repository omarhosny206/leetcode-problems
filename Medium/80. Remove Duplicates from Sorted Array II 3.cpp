// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1;
        int freq = 1;

        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[j] == nums[j - 1])
                freq++;

            else
                freq = 1;

            if (freq <= 2)
            {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};