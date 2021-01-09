// https://leetcode.com/problems/majority-element-ii/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result;
        int size = nums.size();
        int num1 = -1, num2 = -1, count_num1 = 0, count_num2 = 0;

        for (auto num : nums)
        {
            if (num == num1)
                count_num1++;

            else if (num == num2)
                count_num2++;

            else if (count_num1 == 0)
            {
                num1 = num;
                count_num1++;
            }

            else if (count_num2 == 0)
            {
                num2 = num;
                count_num2++;
            }

            else
            {
                count_num1--;
                count_num2--;
            }
        }

        count_num1 = count_num2 = 0;

        for (auto num : nums)
        {
            if (num == num1)
                count_num1++;

            else if (num == num2)
                count_num2++;
        }

        if (count_num1 > size / 3)
            result.push_back(num1);

        if (count_num2 > size / 3)
            result.push_back(num2);

        return result;
    }
};