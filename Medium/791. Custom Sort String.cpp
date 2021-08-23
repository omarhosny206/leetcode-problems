// https://leetcode.com/problems/custom-sort-string/

class Solution
{
public:
    string customSortString(string order, string s)
    {
        string result = "";
        unordered_map<char, int> freq;

        for (char &c : s)
            freq[c]++;

        for (char &c : order)
            while (freq[c]-- > 0)
                result += c;

        for (auto &pair : freq)
            while (pair.second-- > 0)
                result += pair.first;

        return result;
    }
};