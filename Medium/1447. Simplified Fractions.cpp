// https://leetcode.com/problems/simplified-fractions/

class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> result;

        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (gcd(j, i) == 1)
                    result.push_back(to_string(i) + "/" + to_string(j));

        return result;
    }

    int gcd(int first, int second)
    {
        if (second == 0)
            return first;

        return gcd(second, first % second);
    }
};