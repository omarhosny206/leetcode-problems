// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution
{
public:
    int minPartitions(string n)
    {
        int result = INT_MIN;

        for (char &c : n)
            result = max(result, c - '0');

        return result;
    }
};