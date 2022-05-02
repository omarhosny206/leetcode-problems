
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int index = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
            {
                int temp = nums[index];
                nums[index++] = nums[i];
                nums[i] = temp;
            }
        }

        return nums;
    }
};