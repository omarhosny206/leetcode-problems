// https://leetcode.com/problems/minimum-distance-to-the-target-element/

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        if (nums[start] == target)
            return 0;

        int left = leftSearch(nums, target, 0, start - 1);
        int right = rightSearch(nums, target, start + 1, nums.size() - 1);

        if (left == -1 || right == -1)
            return abs(start - max(left, right));

        left = abs(start - left);
        right = abs(start - right);
        return min(left, right);
    }

    int rightSearch(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            if (nums[start] == target)
                return start;
            start++;
        }

        return -1;
    }

    int leftSearch(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            if (nums[end] == target)
                return end;
            end--;
        }

        return -1;
    }
};