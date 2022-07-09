// https://leetcode.com/problems/jump-game-vi/

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size());
        priority_queue<pair<int, int>> maxHeap;

        dp[nums.size() - 1] = nums[nums.size() - 1];

        maxHeap.push({dp[nums.size() - 1], nums.size() - 1});

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            while (maxHeap.size() && maxHeap.top().second > i + k)
                maxHeap.pop();

            dp[i] = maxHeap.top().first + nums[i];
            maxHeap.push({dp[i], i});
        }

        return dp[0];
    }
};