// https://leetcode.com/problems/roman-to-integer/

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        if (s.length() == 1)
            return value[s[0]];

        char current = s[0];
        char next = s[1];

        for (int i = 0; i < s.length(); ++i)
        {
            next = s[i + 1];
            sum += value[current] >= value[next] ? value[current] : -value[current];
            current = next;
        }

        return sum;
    }
};