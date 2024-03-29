// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int i = 0;
        sort(nums.begin(), nums.end());

        while (i < nums.size() - 2)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            int target = -nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums.size() && nums[j] == nums[j - 1])
                        j++;

                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }

                else if (nums[j] + nums[k] < target)
                    j++;

                else
                    k--;
            }

            int value = nums[i];
            while (i < nums.size() && nums[i] == value)
                i++;
        }

        return result;
    }
};