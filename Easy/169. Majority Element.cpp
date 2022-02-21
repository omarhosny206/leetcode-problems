// https://leetcode.com/problems/majority-element/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorityNumber = nums[0];
        int counter = 0;

        for (int &num : nums)
        {
            if (num == majorityNumber)
                counter++;

            else
                counter--;

            if (counter < 0)
            {
                majorityNumber = num;
                counter = 1;
            }
        }

        return majorityNumber;
    }
};