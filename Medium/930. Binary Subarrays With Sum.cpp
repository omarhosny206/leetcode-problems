class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;

        for (int i = 0; i < A.size(); ++i)
        {
            sum += A[i];
            if (seen.find(sum - S) != seen.end())
                result += seen[sum - S];

            seen[sum]++;
        }

        return result;
    }
};