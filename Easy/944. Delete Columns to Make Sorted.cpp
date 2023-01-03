// https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int result = 0;

        for (int j = 0; j < strs[0].size(); ++j)
        {
            bool isSorted = true;
            char previous = strs[0][j];

            for (int i = 0; i < strs.size(); ++i)
            {
                char current = strs[i][j];

                if (current < previous)
                {
                    isSorted = false;
                    break;
                }

                previous = current;
            }

            if (!isSorted)
                result++;
        }

        return result;
    }
};