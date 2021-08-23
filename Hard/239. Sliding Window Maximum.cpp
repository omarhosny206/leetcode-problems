// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> values;
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            while (!values.empty() && values.back() < nums[j])
                values.pop_back();

            values.push_back(nums[j]);

            if (j - i + 1 == k)
            {
                result.push_back(values.front());

                if (values.front() == nums[i])
                    values.pop_front();

                i++;
            }

            j++;
        }

        return result;
    }
};