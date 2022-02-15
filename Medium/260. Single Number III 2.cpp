// https://leetcode.com/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int &num : nums)
            freq[num]++;

        for (int &num : nums)
            if (freq[num] == 1)
                result.push_back(num);

        return result;
    }
};