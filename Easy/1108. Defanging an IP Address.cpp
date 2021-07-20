// https://leetcode.com/problems/defanging-an-ip-address/

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string result = "";

        for (char &c : address)
        {
            if (c == '.')
                result += "[.]";

            else
                result += c;
        }

        return result;
    }
};