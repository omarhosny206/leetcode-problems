// https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int i = 0;
        int j = A.size() - 1;
        vector<int> result(A.size());

        for (int num : A)
        {
            if (num % 2 == 0)
                result[i++] = num;
            else
                result[j--] = num;
        }

        return result;
    }
};