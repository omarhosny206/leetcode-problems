// https://leetcode.com/problems/fizz-buzz/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        int i = 1;
        while (i <= n)
        {
            if (i % 3 == 0 && i % 5 == 0)
                result.push_back("FizzBuzz");

            else if (i % 3 == 0)
                result.push_back("Fizz");

            else if (i % 5 == 0)
                result.push_back("Buzz");

            else
                result.push_back(to_string(i));

            i++;
        }

        return result;
    }
};