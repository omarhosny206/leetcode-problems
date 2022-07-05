// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, bool> seen;

        for (int &num : nums)
            seen[num] = true;

        for (int &num : nums)
        {
            bool isFirstNumber = (seen[num - 1] == false);

            if (isFirstNumber)
            {
                int counter = 1;
                int next = num + 1;

                while (seen[next])
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