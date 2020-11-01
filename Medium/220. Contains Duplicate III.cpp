// https://leetcode.com/problems/contains-duplicate-iii/

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (k <= 0)
            return false;

        if (k >= nums.size())
            k = nums.size() - 1;

        set<long long> numbers;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                numbers.erase(nums[i - k - 1]);

            auto position = numbers.lower_bound((long long)nums[i] - t);

            if ((position != numbers.end() && abs(*position - nums[i]) <= t))
                return true;

            numbers.insert(nums[i]);
        }

        return false;
    }
};