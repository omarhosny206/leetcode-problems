// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        unordered_set<int> numbers;

        for (int num : A)
        {
            if (numbers.find(num) != numbers.end())
                return num;
            numbers.insert(num);
        }

        return 1;
    }
};