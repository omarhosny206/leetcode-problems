// https://leetcode.com/problems/4sum-ii/

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int result = 0;
        unordered_map<int, int> sumFrequency;

        for (int a : A)
            for (int b : B)
                sumFrequency[a + b]++;

        for (int c : C)
            for (int d : D)
                result += sumFrequency[-(c + d)];

        return result;
    }
};