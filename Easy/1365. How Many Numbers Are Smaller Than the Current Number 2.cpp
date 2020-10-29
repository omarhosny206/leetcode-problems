// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j != i && nums[i] > nums[j])
                    count++;
            }
            result.push_back(count);
        }

        return result;
    }
};