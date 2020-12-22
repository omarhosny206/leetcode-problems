// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int answer = INT_MAX;
        int left = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            while (sum >= s)
            {
                answer = min(answer, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return answer != INT_MAX ? answer : 0;
    }
};