// https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int result = 0;
        unordered_map<int, int> freq;
        vector<int> nums;
        int sum = 0;
        int half = arr.size() / 2;

        for (int num : arr)
            freq[num]++;

        for (auto pair : freq)
            nums.push_back(pair.second);

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 0 && sum < half; --i)
        {
            result++;
            sum += nums[i];
        }

        return result;
    }
};