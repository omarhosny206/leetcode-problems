// https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int i = 0;
        int j = A.size() - 1;
        vector<int> result(A.size());

        for (int num : A)
        {
            if (num % 2 == 0)
            {
                result[i] = num;
                i += 2;
            }

            else
            {
                result[j] = num;
                j -= 2;
            }
        }

        return result;
    }
};