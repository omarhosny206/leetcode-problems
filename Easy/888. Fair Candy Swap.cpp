// https://leetcode.com/problems/fair-candy-swap/

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sum_a = 0;
        int sum_b = 0;

        for (int size : A)
            sum_a += size;
        for (int size : B)
            sum_b += size;

        int delta = (sum_b - sum_a) / 2;
        unordered_set<int> candy_size;

        for (int size : B)
            candy_size.insert(size);

        for (int size : A)
            if (candy_size.find(size + delta) != candy_size.end())
                return {size, size + delta};

        return {};
    }
};