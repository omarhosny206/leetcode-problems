// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int result = 0;

        for (string &operation : operations)
            result += (operation[1] == '+') ? 1 : -1;

        return result;
    }
};