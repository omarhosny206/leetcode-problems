// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int result = 0;

        if (k == 0)
        {
            unordered_map<int, int> freq;

            for (int &num : nums)
                freq[num]++;

            for (auto &pair : freq)
                if (pair.second > 1)
                    result++;
        }

        else
        {
            unordered_set<int> seen;

            for (const int &num : nums)
                seen.insert(num);

            for (const int &num : seen)
                if (seen.find(k + num) != seen.end())
                    result++;
        }

        return result;
    }
};