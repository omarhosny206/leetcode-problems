// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> nums;
        int i = 0;
        int j = 0;

        while (i < pushed.size() && j < popped.size())
        {
            nums.push(pushed[i++]);
            while (!nums.empty() && nums.top() == popped[j])
            {
                nums.pop();
                j++;
            }
        }

        return nums.empty();
    }
};