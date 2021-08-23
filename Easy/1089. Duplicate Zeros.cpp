// https://leetcode.com/problems/duplicate-zeros/

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int i = 0;

        while (i < arr.size())
        {
            if (arr[i] == 0)
            {
                arr.pop_back();
                arr.insert(arr.begin() + i, 0);
                i += 2;
            }

            else
                i++;
        }
    }
};