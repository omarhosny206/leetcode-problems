// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        map<int, int> numbers;
        for (int num : nums)
            numbers[num]++;

        while (!numbers.empty())
        {
            int firstNumber = numbers.begin()->first;
            for (int i = firstNumber; i < firstNumber + k; ++i)
            {
                if (numbers.find(i) == numbers.end())
                    return false;
                numbers[i]--;

                if (numbers[i] < 1)
                    numbers.erase(i);
            }
        }

        return true;
    }
};