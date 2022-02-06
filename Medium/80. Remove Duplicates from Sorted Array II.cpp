// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;

        for (int &num : nums)
        {
            if (i < 2 || num != nums[i - 2])
            {
                nums[i] = num;
                i++;
            }
        }

        return i;
    }
};