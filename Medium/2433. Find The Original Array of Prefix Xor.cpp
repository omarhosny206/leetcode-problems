// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> result(pref.size());
        int previousXor = pref[0];
        result[0] = pref[0];

        for (int i = 1; i < pref.size(); ++i)
        {
            result[i] = previousXor ^ pref[i];
            previousXor ^= result[i];
        }

        return result;
    }
};