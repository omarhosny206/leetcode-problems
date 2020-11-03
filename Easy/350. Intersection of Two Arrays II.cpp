// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        for (int n : nums1)
            freq[n]++;

        for (int n : nums2)
        {
            if (freq[n] > 0)
            {
                result.push_back(n);
                freq[n]--;
            }
        }

        return result;
    }
};