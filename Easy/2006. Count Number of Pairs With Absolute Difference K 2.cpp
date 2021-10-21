// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, vector<int>> seen;

        for (int i = 0; i < nums.size(); ++i)
            seen[nums[i]].push_back(i);

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int firstComplement = nums[i] - k;
            int secondComplement = nums[i] + k;
            result += countPairs(nums, seen, k, i, firstComplement) + countPairs(nums, seen, k, i, secondComplement);
        }

        return result;
    }

    int countPairs(vector<int> &nums, unordered_map<int, vector<int>> &seen, int k, int i, int complement)
    {
        int result = 0;

        if (seen.find(complement) != seen.end())
            for (int &j : seen[complement])
                if (j > i && abs(nums[i] - complement) == k)
                    result++;

        return result;
    }
};