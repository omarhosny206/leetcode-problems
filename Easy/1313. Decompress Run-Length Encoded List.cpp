// https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); i += 2)
        {
            int freq = nums[i];
            while (freq--)
                result.push_back(nums[i + 1]);
        }

        return result;
    }
};