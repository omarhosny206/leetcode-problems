// https://leetcode.com/problems/sort-an-array/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        heapSort(nums, nums.size());
        return nums;
    }

    void heapSort(vector<int> &nums, int size)
    {
        for (int i = (size / 2) - 1; i >= 0; i--)
            siftDown(nums, size, i);

        for (int i = size - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
    }

    void siftDown(vector<int> &nums, int Size, int initialPosition)
    {

        int left = (2 * initialPosition) + 1;
        int right = (2 * initialPosition) + 2;
        int maxValue = initialPosition;

        if (left < Size && nums[left] > nums[maxValue])
            maxValue = left;

        if (right < Size && nums[right] > nums[maxValue])
            maxValue = right;

        if (maxValue != initialPosition)
        {
            swap(nums[initialPosition], nums[maxValue]);
            siftDown(nums, Size, maxValue);
        }
    }
};