// https://leetcode.com/problems/to-lower-case/

class Solution
{
public:
    string toLowerCase(string str)
    {
        string result = "";
        for (char c : str)
        {
            if (c >= 65 && c <= 92)
                result += c + 32;
            else
                result += c;
        }
        return result;
    }
};