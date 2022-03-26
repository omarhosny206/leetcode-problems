// https://leetcode.com/problems/binary-search/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        return binarySearch(nums, target, left, right);
    }

    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
                return middle;

            else if (nums[middle] > target)
                right = middle - 1;

            else
                left = middle + 1;
        }

        return -1;
    }
};