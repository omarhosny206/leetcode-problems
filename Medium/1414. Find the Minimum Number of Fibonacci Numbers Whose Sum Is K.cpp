// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        int result = 0;
        vector<int> fibonacci;

        fibonacci.push_back(0);
        fibonacci.push_back(1);
        int i = 2;

        while (fibonacci.back() < k)
        {
            fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
            i++;
        }

        int index = fibonacci.size() - 1;

        while (k != 0)
        {
            while (fibonacci[index] <= k)
            {
                k -= fibonacci[index];
                result++;
            }

            index--;
        }

        return result;
    }
};