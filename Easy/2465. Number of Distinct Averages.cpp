// https://leetcode.com/problems/number-of-distinct-averages/

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int result = 0;
        unordered_map<double, int> freq;
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            double average = (double)(nums[i] + nums[j]) / 2;
            freq[average]++;

            i++;
            j--;
        }

        result = freq.size();
        return result;
    }
};