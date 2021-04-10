// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int result = INT_MIN;
        int i = 0;
        int j = 0;
        int zeroCounter = 0;

        while (j < A.size())
        {
            if (A[j] == 0)
                zeroCounter++;

            if (zeroCounter > K)
            {
                while (i < j && A[i] == 1)
                    i++;

                i++;
                zeroCounter--;
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};