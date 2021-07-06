// https://leetcode.com/problems/gray-code/

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result = Generate(n);
        return result;
    }

    vector<int> Generate(int n)
    {
        vector<int> result;

        if (n == 0)
            return {0};

        result = Generate(n - 1);

        int size = result.size();
        for (int i = size - 1; i >= 0; --i)
            result.push_back(result[i] | (1 << (n - 1)));

        return result;
    }
};