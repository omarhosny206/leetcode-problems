// https://leetcode.com/problems/maximum-69-number/

class Solution
{
public:
    int maximum69Number(int num)
    {
        string number = to_string(num);

        for (char &digit : number)
        {
            if (digit == '6')
            {
                digit = '9';
                break;
            }
        }

        int result = stoi(number);
        return result;
    }
};