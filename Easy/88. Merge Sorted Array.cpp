// https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        for (int index = nums1.size() - 1;
             index >= 0; --index)
        {
            if (m > 0 && n > 0)
            {
                if (nums1[m - 1] >= nums2[n - 1])
                    nums1[index] = nums1[--m];

                else
                    nums1[index] = nums2[--n];
            }
            else if (n > 0)
                nums1[index] = nums2[--n];
        }
    }
};