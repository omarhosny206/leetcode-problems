// https://leetcode.com/problems/shuffle-the-array/

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int i = 0, j = n;
        vector<int> result;
        while (i < n)
        {
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            i++;
            j++;
        }
        return result;
    }
};