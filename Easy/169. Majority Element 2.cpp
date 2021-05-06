// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> freq;
        int size = nums.size() / 2;

        for (int num : nums)
            freq[num]++;

        for (int num : nums)
            if (freq[num] > size)
                return num;

        return 0;
    }
};