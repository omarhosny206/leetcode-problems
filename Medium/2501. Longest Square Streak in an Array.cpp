// https://leetcode.com/problems/longest-square-streak-in-an-array/

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int result = INT_MIN;
        unordered_set<double> values;

        for (int &num : nums)
            values.insert(num);

        for (int num : nums)
        {
            int counter = countRoots(values, num);

            if (counter >= 2)
                result = max(result, counter);
        }

        return result == INT_MIN ? -1 : result;
    }

    int countRoots(unordered_set<double> &values, int &num)
    {
        int counter = 0;

        double value = num;

        while (values.find(value) != values.end())
        {
            counter++;
            value = sqrt(value);
        }

        return counter;
    }
};