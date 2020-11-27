// https://leetcode.com/problems/excel-sheet-column-number/

class Solution
{
public:
    int titleToNumber(string s)
    {
        int answer = 0;
        int power = 0;
        int size = s.size();

        for (int i = size - 1; i >= 0; --i)
            answer += (s[i] - 64) * pow(26, power++);

        return answer;
    }
};