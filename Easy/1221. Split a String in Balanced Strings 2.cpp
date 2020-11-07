// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        if (s.length() <= 1)
            return 0;

        int answer = 0;
        stack<char> letters;

        for (int i = 0; i < s.length(); ++i)
        {

            if (letters.empty())
                letters.push(s[i]);

            else if (s[i] == letters.top())
                letters.push(s[i]);
            else
            {
                letters.pop();
                if (letters.empty())
                    answer++;
            }
        }
        return answer;
    }
};