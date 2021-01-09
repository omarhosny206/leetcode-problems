// https://leetcode.com/problems/majority-element-ii/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        int size = nums.size();

        for (int num : nums)
            freq[num]++;

        for (auto pair : freq)
            if (pair.second > size / 3)
                result.push_back(pair.first);

        return result;
    }
};