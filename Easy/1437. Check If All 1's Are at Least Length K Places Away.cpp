// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int position = -nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                if (i - position < k)
                    return false;

                position = i + 1;
            }
        }

        return true;
    }
};