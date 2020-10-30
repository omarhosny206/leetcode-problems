// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution
{
public:
    unordered_map<int, int> table;
    int tribonacci(int n)
    {
        if (table.find(n) != table.end())
            return table[n];

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        int result = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        table[n] = result;
        return result;
    }
};