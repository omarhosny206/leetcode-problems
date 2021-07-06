// https://leetcode.com/problems/gray-code/

class Solution
{
    vector<int> result;

public:
    vector<int> grayCode(int n)
    {
        Generate(n);
        return result;
    }

    void Generate(int n)
    {
        if (n == 1)
        {
            result.push_back(0);
            result.push_back(1);
            return;
        }

        Generate(n - 1);

        int size = result.size();
        for (int i = size - 1; i >= 0; --i)
            result.push_back(result[i] | (1 << (n - 1)));
    }
};