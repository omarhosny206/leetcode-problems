// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution
{
public:
    string makeFancyString(string s)
    {
        string result = "";
        char current = ' ';
        int counter = 0;

        for (char &c : s)
        {
            if (current != c)
            {
                current = c;
                counter = 0;
            }

            counter++;

            if (counter < 3)
                result += c;
        }

        return result;
    }
};