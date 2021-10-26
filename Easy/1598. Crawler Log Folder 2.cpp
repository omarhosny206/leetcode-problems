// https://leetcode.com/problems/crawler-log-folder/

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int depth = 0;

        for (string &directory : logs)
        {
            if (directory != "./")
            {
                if (directory == "../")
                {
                    if (depth > 0)
                        depth--;
                }

                else
                    depth++;
            }
        }

        return depth;
    }
};