
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = nums1.size() - 1; i >= 0; --i)
        {
            if (m > 0 && n > 0)
            {
                if (nums1[m - 1] >= nums2[n - 1])
                    nums1[i] = nums1[--m];

                else
                    nums1[i] = nums2[--n];
            }

            else if (n > 0)
                nums1[i] = nums2[--n];
        }
    }
};