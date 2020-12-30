// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        if (m * k > arr.size())
            return false;

        int counter = 0;

        for (int i = 0; i < arr.size() - m; ++i)
        {
            counter = (arr[i] == arr[i + m]) ? counter + 1 : 0;

            if (counter == m * (k - 1))
                return true;
        }

        return false;
    }
};