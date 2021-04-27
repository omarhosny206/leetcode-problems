// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int result = 0;
        int sum = 0;
        int i = 0;

        for (int j = 0; j < arr.size(); ++j)
        {
            sum += arr[j];
            int windowSize = j - i + 1;

            if (windowSize == k)
            {
                result += ((sum / k) >= threshold);
                sum -= arr[i];
                i++;
            }
        }

        return result;
    }
};