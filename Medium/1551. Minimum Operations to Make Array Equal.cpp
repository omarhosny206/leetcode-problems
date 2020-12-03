// https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution
{
public:
    int minOperations(int n)
    {
        int numOperations = 0;
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            numOperations += (((high * 2) + 1) - ((low * 2) + 1)) / 2;
            low++;
            high--;
        }

        return numOperations;
    }
};