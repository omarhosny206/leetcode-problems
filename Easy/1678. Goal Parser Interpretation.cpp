// https://leetcode.com/problems/goal-parser-interpretation/

class Solution
{
public:
    string interpret(string command)
    {
        string result = "";
        string temp = "";

        for (char c : command)
        {
            if (c == 'G')
                result += 'G';

            else if (c == ')')
            {
                if (temp.length() > 1)
                    result += "al";
                else
                    result += 'o';

                temp = "";
            }

            else
                temp += c;
        }

        return result;
    }
};