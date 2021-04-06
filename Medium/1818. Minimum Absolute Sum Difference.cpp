// https://leetcode.com/problems/minimum-absolute-sum-difference/

class Solution
{
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1 == nums2)
            return 0;

        int sum = 0;
        int mod = 1e9 + 7;
        int maxDifference = INT_MIN;
        int minDifference = INT_MAX;
        int index = 0;

        for (int i = 0; i < nums1.size(); ++i)
        {
            int difference = abs(nums1[i] - nums2[i]);
            sum = (sum + difference) % mod;

            if (difference >= maxDifference)
            {
                maxDifference = difference;
                index = i;
            }
        }

        sum -= maxDifference;

        for (int i = 0; i < nums1.size(); ++i)
            minDifference = min(minDifference, abs(nums1[i] - nums2[index]));

        sum += minDifference;

        return sum % mod;
    }
};