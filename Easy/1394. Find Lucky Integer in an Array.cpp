// https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int result = -1;
        map<int, int> freq;

        for (int num : arr)
            freq[num]++;

        for (pair<int, int> p : freq)
            if (p.first == p.second)
                result = p.first;

        return result;
    }
};