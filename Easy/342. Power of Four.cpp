// https://leetcode.com/problems/power-of-four/

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        vector<int> numbers = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576,
                               4194304, 16777216, 67108864, 268435456, 1073741824};

        return binarySearch(num, 0, numbers.size() - 1, numbers);
    }

    bool binarySearch(int num, int left, int right, vector<int> &numbers)
    {
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (numbers[middle] == num)
                return true;
            if (numbers[middle] > num)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return false;
    }
};