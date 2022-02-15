// https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> values;

        for (int &num : nums)
        {
            if (values.find(num) != values.end())
                values.erase(num);

            else
                values.insert(num);
        }

        for (const int &num : values)
            return num;

        return 0;
    }
};