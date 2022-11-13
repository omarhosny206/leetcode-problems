// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/

class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int result = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int currentLcm = nums[i];

            for (int j = i; j < nums.size(); ++j)
            {
                currentLcm = lcm(currentLcm, nums[j]);

                if (currentLcm == k)
                    result++;
            }
        }

        return result;
    }

    long long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    long long gcd(long long int a, long long int b)
    {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }
};