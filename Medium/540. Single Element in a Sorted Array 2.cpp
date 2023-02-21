class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int result = 0;

        for (int &num : nums)
            result ^= num;

        return result;
    }
};