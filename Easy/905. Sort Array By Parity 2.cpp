// https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int i = 0;
        vector<int> result(A.size());

        for (int num : A)
            if (num % 2 == 0)
                result[i++] = num;

        for (int num : A)
            if (num % 2 != 0)
                result[i++] = num;

        return result;
    }
};