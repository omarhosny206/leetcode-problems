// https://leetcode.com/problems/3sum-closest/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            if (i == 0 || nums[i] != nums[i - 1])
            {
                while (j < k)
                {
                    int currentSum = nums[i] + nums[j] + nums[k];

                    if (currentSum == target)
                        return currentSum;

                    if (abs(target - currentSum) < abs(target - result))
                        result = currentSum;

                    if (currentSum > target)
                        k--;

                    else
                        j++;
                }
            }
        }

        return result;
    }
};