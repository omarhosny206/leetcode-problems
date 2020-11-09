// https://leetcode.com/problems/largest-number/

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        if (nums.empty())
            return "0";

        if (count(nums.begin(), nums.end(), 0) == nums.size())
            return "0";

        if (nums.size() == 1)
            return to_string(nums[0]);

        string result = "";
        sort(nums.begin(), nums.end(), compare);

        for (int num : nums)
            result += to_string(num);

        return result;
    }

    static bool compare(const int a, const int b)
    {
        string first = to_string(a);
        string second = to_string(b);
        return first + second >= second + first;
    }
};