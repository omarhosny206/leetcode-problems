// https://leetcode.com/problems/valid-mountain-array/

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;

        int i = 0;

        while (i + 1 < arr.size() && arr[i] < arr[i + 1])
            i++;

        if (i == 0 || i == arr.size() - 1)
            return false;

        while (i + 1 < arr.size() && arr[i] > arr[i + 1])
            i++;

        return i == arr.size() - 1;
    }
};