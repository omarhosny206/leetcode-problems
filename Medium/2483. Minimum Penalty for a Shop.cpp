// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int result = -1;
        int current = INT_MAX;

        vector<int> left(customers.size() + 1);
        vector<int> right(customers.size() + 1);
        int numY = 0;
        int numN = 0;

        for (int i = customers.size() - 1; i >= 0; --i)
        {
            if (customers[i] == 'Y')
                numY++;

            right[i] = numY;
        }

        for (int i = 0; i < customers.size(); ++i)
        {
            left[i] = numN;

            if (customers[i] == 'N')
                numN++;
        }

        left[customers.size()] = numN;

        for (int i = 0; i < left.size(); ++i)
        {
            if (left[i] + right[i] < current)
            {
                current = left[i] + right[i];
                result = i;
            }
        }

        return result;
    }
};