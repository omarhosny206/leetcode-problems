// https://leetcode.com/problems/3sum-closest/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        if (nums.size() < 3)
            return {};
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            if (i == 0 || nums[i] != nums[i - 1])
                while (j < k)
                {

                    int tempSum = nums[i] + nums[j] + nums[k];

                    if (tempSum == target)
                        return tempSum;

                    if (abs(target - sum) > abs(target - tempSum))
                        sum = tempSum;

                    if (tempSum > target)
                        k--;

                    else if (tempSum < target)
                        j++;
                }
        }

        return sum;
    }
};