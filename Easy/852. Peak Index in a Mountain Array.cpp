// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;
        int answer = binarySearch(arr, left, right);

        return answer;
    }

    int binarySearch(vector<int> &arr, int left, int right)
    {

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (arr[middle] < arr[middle + 1])
                left = middle + 1;

            else
                right = middle;
        }

        return left;
    }
};