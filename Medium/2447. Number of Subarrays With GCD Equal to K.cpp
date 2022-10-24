// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/

class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int result = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int currentGcd = getGcd(nums[i], nums[i]);

            for (int j = i; j < nums.size(); ++j)
            {
                currentGcd = getGcd(currentGcd, nums[j]);

                if (currentGcd == k)
                    result++;

                else if (nums[j] % k != 0)
                    break;
            }
        }

        return result;
    }

    int getGcd(int a, int b)
    {
        if (b == 0)
            return a;

        return getGcd(b, a % b);
    }
};