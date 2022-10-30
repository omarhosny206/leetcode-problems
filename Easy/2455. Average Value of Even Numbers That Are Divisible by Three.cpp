// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int result = 0;
        int sum = 0;
        int counter = 0;

        for (int &num : nums)
        {
            if (num % 2 == 0 && num % 3 == 0)
            {
                sum += num;
                counter++;
            }
        }

        if (counter == 0)
            return 0;

        result = sum / counter;
        return result;
    }
};