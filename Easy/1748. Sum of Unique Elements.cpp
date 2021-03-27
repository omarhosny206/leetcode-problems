// https://leetcode.com/problems/sum-of-unique-elements/

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int sum = 0;
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        for (auto pair : freq)
            if (pair.second == 1)
                sum += pair.first;

        return sum;
    }
};