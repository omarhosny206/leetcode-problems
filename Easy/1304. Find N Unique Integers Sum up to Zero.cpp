// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> result;

        for (int i = 0; i < n / 2; ++i)
        {
            result.push_back(i + 1);
            result.push_back(-(i + 1));
        }

        if (n % 2 == 1)
            result.push_back(0);

        return result;
    }
};