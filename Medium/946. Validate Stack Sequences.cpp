// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> nums;
        int index = 0;

        for (int i = 0; i < pushed.size(); ++i)
        {
            nums.push(pushed[i]);
            while (!nums.empty() && nums.top() == popped[index])
            {
                nums.pop();
                index++;
            }
        }

        return nums.empty();
    }
};