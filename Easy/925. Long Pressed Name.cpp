// https://leetcode.com/problems/long-pressed-name/

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0;
        int j = 0;

        while (i < name.length() && j < typed.length())
        {
            char ch1 = name[i];
            char ch2 = typed[j];
            int counter = 0;

            if (ch1 != ch2)
                return false;

            while (name[i] == ch1)
            {
                i++;
                counter--;
            }

            while (typed[j] == ch2)
            {
                j++;
                counter++;
            }

            if (counter < 0)
                return false;
        }

        return i == name.length() && j == typed.length();
    }
};