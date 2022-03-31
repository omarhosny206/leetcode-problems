// https://leetcode.com/problems/split-array-largest-sum/

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int sum = 0;
        int maxNumber = INT_MIN;

        for (int &num : nums)
        {
            maxNumber = max(maxNumber, num);
            sum += num;
        }

        return binarySearch(nums, m, maxNumber, sum);
    }

    int binarySearch(vector<int> &nums, int m, int left, int right)
    {
        int result = -1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (isValid(nums, m, middle))
            {
                result = middle;
                right = middle - 1;
            }

            else
                left = middle + 1;
        }

        return result;
    }

    bool isValid(vector<int> &nums, int m, int maxNumber)
    {
        int sum = 0;
        int index = 1;

        for (int &num : nums)
        {
            sum += num;

            if (sum > maxNumber)
            {
                index++;
                sum = num;
            }

            if (index > m)
                return false;
        }

        return true;
    }
};