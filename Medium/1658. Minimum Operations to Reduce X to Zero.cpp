// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int left = 0;
        int right = nums.size() - 1;
        int sum = 0;
        int answer = -1;

        while (left <= right && sum < x)
            sum += nums[left++];

        while (left >= 0)
        {
            if (sum == x)
            {
                int operations = left + nums.size() - right - 1;
                if (answer == -1 || answer > operations)
                    answer = operations;
            }

            if (sum >= x)
            {
                if (left == 0)
                    break;
                sum -= nums[--left];
            }
            else
            {
                if (left >= right)
                    break;
                sum += nums[right--];
            }
        }

        return answer;
    }
};