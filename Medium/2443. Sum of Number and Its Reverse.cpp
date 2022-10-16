// https://leetcode.com/problems/sum-of-number-and-its-reverse/

class Solution
{
public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = num; i >= 0; --i)
        {
            int first = i;
            int second = reverse(first);

            if (first + second == num)
                return true;
        }

        return false;
    }

    int reverse(int num)
    {
        int result = 0;

        while (num > 0)
        {
            result = result * 10 + num % 10;
            num /= 10;
        }

        return result;
    }
};