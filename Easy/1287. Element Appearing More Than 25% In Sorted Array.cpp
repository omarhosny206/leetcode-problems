// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int times = arr.size() / 4;
        for (int i = 0; i + times < arr.size(); ++i)
            if (arr[i] == arr[i + times])
                return arr[i];

        return -1;
    }
};