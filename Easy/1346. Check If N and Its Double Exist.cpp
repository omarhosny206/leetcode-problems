// https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> nums;
        for (int n : arr)
        {

            if (nums.find(n * 2) != nums.end() || (n % 2 == 0) && nums.find(n / 2) != nums.end())
                return true;
            else
                nums.insert(n);
        }

        return false;
    }
};