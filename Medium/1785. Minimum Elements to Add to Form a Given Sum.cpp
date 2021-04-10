// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long answer = 0;
        long sum = 0;
        for (int num : nums)
            sum += num;

        long difference = abs(goal - sum);
        answer += abs(difference / limit);

        return (difference % limit == 0) ? answer : answer + 1;
    }
};