// https://leetcode.com/problems/delete-and-earn/

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = 10001;

        if (nums.size() == 1)
            return nums[0];

        vector<int> map(n, 0);

        for (auto &num : nums)
        {
            map[num] += num;
        }

        int one = map[0];
        int two = max(one, map[1]);

        for (int i = 2; i < n; i++)
        {
            int cur = max(two, one + map[i]);
            one = two;
            two = cur;
        }

        return max(one, two);
    }
};