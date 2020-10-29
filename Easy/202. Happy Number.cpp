// https://leetcode.com/problems/happy-number/

class Solution
{
public:
    bool isHappy(int n)
    {

        unordered_set<int> seen;

        while (n != 1)
        {
            int curr = n;
            int sum = 0;

            while (curr > 0)
            {
                sum += ((curr % 10) * (curr % 10));
                curr /= 10;
            }

            if (seen.find(sum) != seen.end())
                return false;

            seen.insert(sum);
            n = sum;
        }

        return true;
    }
};