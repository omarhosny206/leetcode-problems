// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int answer = 1;
        int counter = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                answer = max(answer, counter);
                counter = 1;
            }

            else
                counter++;
        }

        answer = max(answer, counter);

        return answer;
    }
};