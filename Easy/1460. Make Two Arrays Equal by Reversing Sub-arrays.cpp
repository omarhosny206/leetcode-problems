// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target.size() != arr.size())
            return false;

        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); ++i)
        {
            freq[arr[i]]++;
            freq[target[i]]--;
        }

        for (auto pair : freq)
            if (pair.second != 0)
                return false;

        return true;
    }
};