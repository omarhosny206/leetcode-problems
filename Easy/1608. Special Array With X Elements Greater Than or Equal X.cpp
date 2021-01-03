// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int answer = -1;

        for (int i = 0; i <= nums.size(); i++)
        {

            int counter = 0;
            int x = i;

            for (int j = 0; j < nums.size(); j++)
                if (nums[j] >= x)
                    counter++;

            if (counter == x)
            {
                answer = x;
                break;
            }
        }

        return answer;
    }
};