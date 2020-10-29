// https://leetcode.com/problems/next-greater-element-i/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> vals;
        vector<int> result;

        for (int i = 0; i < nums2.size(); i++)
            vals[nums2[i]] = i;

        for (int n : nums1)
        {
            bool found = false;
            for (int i = vals[n] + 1; i < nums2.size(); i++)
            {
                if (nums2[i] > n)
                {
                    found = true;
                    result.push_back(nums2[i]);
                    break;
                }
            }
            if (!found)
                result.push_back(-1);
        }

        return result;
    }
};