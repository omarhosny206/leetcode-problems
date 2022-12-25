// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> result;

        sort(nums.begin(), nums.end());

        for (int &query : queries)
        {
            int sum = 0;
            int i = 0;

            while (i < nums.size() && sum + nums[i] <= query)
                sum += nums[i++];

            result.push_back(i);
        }

        return result;
    }
};