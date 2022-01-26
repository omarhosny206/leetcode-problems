// https://leetcode.com/problems/sequential-digits/

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;
        int num = 0;

        for (int i = 1; i < 10; i++)
        {
            num = i;

            for (int j = i + 1; j < 10; j++)
            {
                num = num * 10 + j;

                if (num >= low && num <= high)
                    result.push_back(num);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};