// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution
{
public:
    int largestInteger(int num)
    {
        int result = 0;
        vector<int> evens;
        vector<int> odds;

        string number = to_string(num);
        int i = 0;
        int j = 0;

        while (num > 0)
        {
            if ((num % 10) % 2 == 0)
                evens.push_back(num % 10);

            else
                odds.push_back(num % 10);

            num /= 10;
        }

        sort(evens.begin(), evens.end(), compare);
        sort(odds.begin(), odds.end(), compare);

        for (char &c : number)
        {
            int digit = c - '0';

            if (digit % 2 == 0)
                result = result * 10 + evens[i++];

            else
                result = result * 10 + odds[j++];
        }

        return result;
    }

    static bool compare(int &first, int &second)
    {
        return first > second;
    }
};