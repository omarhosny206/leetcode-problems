// https://leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        if (nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i)
        {
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                int difference = target - (nums[i] + nums[j]);
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    int twoSum = nums[left] + nums[right];

                    if (twoSum == difference)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                    }

                    if (twoSum < difference)
                        left++;

                    else
                        right--;
                }

                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};