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
        int numN = 0;

        for (int i = customers.size() - 1; i >= 0; --i)
            right[i] = (customers[i] == 'Y') ? right[i + 1] + 1 : right[i + 1];

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