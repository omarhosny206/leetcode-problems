// https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int sumModP = 0;

        for (int i = 0; i < nums.size(); i++)
            sumModP = (sumModP + nums[i]) % p;

        if (sumModP == 0)
            return 0;

        unordered_map<int, int> prefixSumModTrack = {{0, -1}};

        int prefixSumModP = 0;
        int minLen = nums.size();
        int modComplement;
        for (int i = 0; i < nums.size(); i++)
        {

            prefixSumModP = (prefixSumModP + nums[i]) % p;

            modComplement = (p + prefixSumModP - sumModP) % p;

            if (prefixSumModTrack.count(modComplement))
                minLen = min(minLen, i - prefixSumModTrack[modComplement]);

            prefixSumModTrack[prefixSumModP] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};