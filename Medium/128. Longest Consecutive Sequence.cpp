// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> numbers;
        for (int num : nums)
            numbers[num] = 1;

        int answer = 0;

        for (int num : nums)
        {
            if (numbers[num - 1] == 0)
            {
                int next = num + 1;
                int counter = 1;

                while (numbers[next] == 1)
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