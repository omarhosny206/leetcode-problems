
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int result = 0;
        stack<int> nums;

        for (string &operation : ops)
        {
            if (operation == "C")
                nums.pop();

            else if (operation == "D")
                nums.push(nums.top() * 2);

            else if (operation == "+")
            {
                int first = nums.top();
                nums.pop();
                int second = nums.top();
                nums.push(first);
                nums.push(first + second);
            }

            else
                nums.push(stoi(operation));
        }

        while (!nums.empty())
        {
            result += nums.top();
            nums.pop();
        }
        
        return result;
    }
};