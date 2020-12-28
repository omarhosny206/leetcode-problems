// https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> result;
        int i = 0;
        int j = 1;

        while (j <= n)
        {
            if (i == target.size())
                break;

            if (j == target[i])
            {
                result.push_back("Push");
                i++;
                j++;
            }

            else
            {
                result.push_back("Push");
                result.push_back("Pop");
                j++;
            }
        }

        return result;
    }
};