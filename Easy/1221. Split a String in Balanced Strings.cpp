// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int answer = 0;
        int count = 0;

        for (int i = 0; i < s.length(); ++i)
        {

            if (s[i] == 'L')
                count++;

            else
                count--;

            if (count == 0)
                answer++;
        }
        return answer;
    }
};