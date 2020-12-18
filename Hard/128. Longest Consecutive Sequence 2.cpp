// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numbers;
        for (int num : nums)
            numbers.insert(num);

        int answer = 0;

        for (int num : nums)
        {
            if (numbers.find(num - 1) == numbers.end())
            {
                int next = num + 1;
                int counter = 1;

                while (numbers.find(next) != numbers.end())
                {
                    next++;
                    counter++;
                }

                answer = max(answer, counter);
            }
        }

        return answer;
    }
};