// https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> nums;
        for (int n : arr)
        {

            if (nums[n * 2] > 0 || (n % 2 == 0) && nums[n / 2] > 0)
                return true;
            else
                nums[n]++;
        }

        return false;
    }
};
