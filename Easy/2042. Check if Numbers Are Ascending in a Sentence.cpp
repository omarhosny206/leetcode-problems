// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int current = INT_MIN;

        for (int i = 0; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
            {
                int number;
                string digits = "";

                while (i < s.length() && isdigit(s[i]))
                    digits += s[i++];

                number = stoi(digits);

                if (current >= number)
                    return false;

                current = number;
            }
        }

        return true;
    }
};