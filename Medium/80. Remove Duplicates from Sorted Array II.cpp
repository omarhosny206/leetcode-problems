// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 0;
        int counter = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1] && counter < 2)
            {
                nums[index++] = nums[i];
                counter++;
            }
            else if (nums[i] != nums[i - 1])
            {
                nums[index++] = nums[i - 1];
                counter = 1;
            }
        }

        nums[index++] = nums[nums.size() - 1];
        return index;
    }
};