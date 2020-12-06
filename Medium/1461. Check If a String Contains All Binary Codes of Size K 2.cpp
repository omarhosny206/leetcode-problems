// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        map<string, int> subset;

        if (k > s.length())
            return false;

        for (int i = 0; i <= s.length() - k; ++i)
            subset[s.substr(i, k)]++;

        return subset.size() == pow(2, k);
    }
};