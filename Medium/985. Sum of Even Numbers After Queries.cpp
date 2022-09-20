// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> result;
        int currentEvenSum = 0;

        for (int &num : nums)
            if (num % 2 == 0)
                currentEvenSum += num;

        for (vector<int> &query : queries)
        {
            int value = query[0];
            int index = query[1];
            int originalValue = nums[index];

            if (originalValue % 2 == 0)
                currentEvenSum -= originalValue;

            nums[index] += value;
            if (nums[index] % 2 == 0)
                currentEvenSum += nums[index];

            result.push_back(currentEvenSum);
        }

        return result;
    }
};