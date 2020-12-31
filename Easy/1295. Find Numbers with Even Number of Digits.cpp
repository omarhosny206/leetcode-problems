// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int result = 0;

        for (int num : nums)
        {
            int num_digits = 0;

            while (num > 0)
            {
                num_digits++;
                num /= 10;
            }

            if (num_digits % 2 == 0)
                result++;
        }

        return result;
    }
};