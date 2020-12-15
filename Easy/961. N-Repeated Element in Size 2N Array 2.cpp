// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        map<int, int> freq;

        for (int num : A)
        {
            freq[num]++;

            if (freq[num] > 1)
                return num;
        }

        return 0;
    }
};