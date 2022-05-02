// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution
{
public:
    int largestInteger(int num)
    {
        int result = 0;
        priority_queue<int> evens;
        priority_queue<int> odds;

        string number = to_string(num);

        while (num > 0)
        {
            if ((num % 10) % 2 == 0)
                evens.push(num % 10);

            else
                odds.push(num % 10);

            num /= 10;
        }

        for (char &c : number)
        {
            int digit = c - '0';

            if (digit % 2 == 0)
            {
                result = result * 10 + evens.top();
                evens.pop();
            }

            else
            {
                result = result * 10 + odds.top();
                odds.pop();
            }
        }

        return result;
    }
};