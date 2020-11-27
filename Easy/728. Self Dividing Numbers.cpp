// https://leetcode.com/problems/self-dividing-numbers/

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        for (int i = left; i <= right; ++i)
        {
            int number = i;
            while (number > 0)
            {
                int temp = number % 10;
                if (temp == 0 || i % temp != 0)
                    break;

                number /= 10;
            }

            if (number == 0)
                result.push_back(i);
        }

        return result;
    }
};