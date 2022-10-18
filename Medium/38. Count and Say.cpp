// https://leetcode.com/problems/count-and-say/

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";

        for (int i = 2; i <= n; ++i)
        {
            string temp = "";
            int j = 0;
            int counter = 0;
            char current = result[j];

            while (j < result.length())
            {
                if (current == result[j])
                    counter++;

                else
                {
                    temp += to_string(counter) + current;
                    current = result[j];
                    counter = 1;
                }

                j++;
            }

            temp += to_string(counter) + current;
            result = temp;
        }

        return result;
    }
};