// https://leetcode.com/problems/counting-elements/

class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        int result = 0;
        unordered_map<int, int> freq;

        for (int &num : arr)
            freq[num]++;

        for (auto &pair : freq)
            if (freq.find(pair.first + 1) != freq.end())
                result += pair.second;

        return result;
    }
};