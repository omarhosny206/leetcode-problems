// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> nums;
        int j = 0;

        for (int i = 0; i < pushed.size(); ++i)
        {
            nums.push(pushed[i]);
            while (!nums.empty() && nums.top() == popped[j])
            {
                nums.pop();
                j++;
            }
        }

        return nums.empty();
    }
};