// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

class Solution
{
public:
    int largestInteger(int num)
    {
        int result = 0;
        vector<int> evens;
        vector<int> odds;
        unordered_set<int> evensPositions;
        unordered_set<int> oddsPositions;

        string number = to_string(num);

        int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;

        while (num > 0)
        {
            if ((num % 10) % 2 == 0)
            {
                evens.push_back(num % 10);
                evensPositions.insert(number.length() - i - 1);
            }

            else
            {
                odds.push_back(num % 10);
                oddsPositions.insert(number.length() - i - 1);
            }

            num /= 10;
            i++;
        }

        sort(evens.begin(), evens.end(), compare);
        sort(odds.begin(), odds.end(), compare);

        for (int l = 0; l < i; ++l)
        {
            if (evensPositions.find(l) != evensPositions.end())
                result = result * 10 + evens[j++];

            else
                result = result * 10 + odds[k++];
        }

        return result;
    }

    static bool compare(int &first, int &second)
    {
        return first > second;
    }
};