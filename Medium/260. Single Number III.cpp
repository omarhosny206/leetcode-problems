// https://leetcode.com/problems/single-number-iii/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> answer = {0, 0};
        int sum = 0, lowBit;

        for (auto num : nums)
            sum ^= num;

        if (sum == INT_MIN)
            lowBit = 0;

        else
            lowBit = sum & (-sum);

        for (auto num : nums)
        {
            if (num & lowBit)
                answer[0] ^= num;

            else
                answer[1] ^= num;
        }

        return answer;
    }
};