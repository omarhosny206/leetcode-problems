// https://leetcode.com/problems/excel-sheet-column-number/

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;

        const int BASE = 26;
        int power = 0;

        for (int i = columnTitle.size() - 1; i >= 0; --i)
            result += (1 + (columnTitle[i] - 'A')) * pow(BASE, power++);

        return result;
    }
};