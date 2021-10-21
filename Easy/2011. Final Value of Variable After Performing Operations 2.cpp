// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int result = 0;

        for (string &operation : operations)
        {
            int i = 0;

            for (i; i < operation.size(); ++i)
                if (operation[i] == '+' || operation[i] == '-')
                    break;

            result += (operation[i] == '+') ? 1 : -1;
        }

        return result;
    }
};