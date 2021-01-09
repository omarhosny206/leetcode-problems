// https://leetcode.com/problems/rotate-function/

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        long result = 0;
        long sum = 0;
        long function = 0;

        for (int i = 0; i < A.size(); ++i)
        {
            sum += (long)A[i];
            function += (long)i * (long)A[i];
        }

        result = function;

        for (int i = 0; i < A.size(); ++i)
        {
            function += sum;
            function -= (long)A[A.size() - 1 - i] * (long)A.size();
            result = max(result, function);
        }

        return result;
    }
};