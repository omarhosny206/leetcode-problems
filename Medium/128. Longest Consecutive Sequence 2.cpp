// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int result = 0;
        unordered_set<int> values;

        for (int &num : nums)
            values.insert(num);

        for (int &num : nums)
        {
            bool isFirstNumber = (values.find(num - 1) == values.end());

            if (isFirstNumber)
            {
                int counter = 1;
                int next = num + 1;

                while (values.find(next) != values.end())
                {
                    counter++;
                    next++;
                }

                result = max(result, counter);
            }
        }

        return result;
    }
};