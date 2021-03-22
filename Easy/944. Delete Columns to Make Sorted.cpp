// https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int result = 0;
        for (int j = 0; j < strs[0].size(); ++j)
        {
            int min = INT_MIN;
            for (int i = 0; i < strs.size(); ++i)
            {
                if (min > strs[i][j] - '0')
                {
                    result++;
                    break;
                }

                min = strs[i][j] - '0';
            }
        }

        return result;
    }
};