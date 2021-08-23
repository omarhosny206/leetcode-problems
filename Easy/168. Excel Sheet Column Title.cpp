// https://leetcode.com/problems/excel-sheet-column-title/

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result = "";

        while (columnNumber > 0)
        {
            columnNumber--;
            result += ((columnNumber % 26) + 'A');
            columnNumber /= 26;
        }

        Reverse(result);

        return result;
    }

    void Reverse(string &result)
    {
        int i = 0;
        int j = result.size() - 1;

        while (i < j)
        {
            char temp = result[i];
            result[i++] = result[j];
            result[j--] = temp;
        }
    }
};