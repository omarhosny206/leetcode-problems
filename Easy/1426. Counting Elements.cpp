// https://leetcode.com/problems/counting-elements/

class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        int result = 0;
        unordered_set<int> nums;

        for (int &num : arr)
            nums.insert(num);

        for (auto &num : arr)
            if (nums.find(num + 1) != nums.end())
                result++;

        return result;
    }
};