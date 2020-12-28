// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int num : arr)
        {
            freq[num]++;
            if (freq[num] > arr.size() / 4)
                return num;
        }

        return -1;
    }
};