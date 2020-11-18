// https://leetcode.com/problems/kth-missing-positive-number/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        unordered_set<int> nums;
        for (int n : arr)
            nums.insert(n);

        int i = 1, counter = 0;

        while (counter < k)
        {
            if (nums.find(i) == nums.end())
                counter++;
            i++;
        }

        return i - 1;
    }
};