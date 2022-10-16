// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        unordered_set<int> vals;

        for (int &num : nums)
        {
            int reversed = reverse(num);
            vals.insert(reversed);
            vals.insert(num);
        }

        return vals.size();
    }

    int reverse(int num)
    {
        int result = 0;

        while (num > 0)
        {
            result = result * 10 + num % 10;
            num /= 10;
        }

        return result;
    }
};