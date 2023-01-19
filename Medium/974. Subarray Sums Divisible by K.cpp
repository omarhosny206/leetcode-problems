class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        int result = 0;
        unordered_map<int, int> prefixSum;
        int sum = 0;
        
        prefixSum[0] = 1;

        for (int num : A)
        {
            sum += num;
            int remaining = sum % K;

            if (remaining < 0)
                remaining += K;

            result += prefixSum[remaining];
            prefixSum[remaining]++;
        }

        return result;
    }
};