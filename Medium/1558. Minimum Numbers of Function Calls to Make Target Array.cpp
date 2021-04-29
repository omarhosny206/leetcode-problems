// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int operationOne = 0;
        int operationTwo = 0;

        for (int num : nums)
        {
            int temp = 0;

            while (num > 0)
            {

                if (num % 2 == 1)
                {
                    operationOne++;
                    num--;
                }

                else
                {
                    num /= 2;
                    temp++;
                }
            }

            operationTwo = max(operationTwo, temp);
        }

        return operationOne + operationTwo;
    }
};