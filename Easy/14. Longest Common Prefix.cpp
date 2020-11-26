// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        int minLength = INT_MAX;

        for (string str : strs)
            minLength = minLength > str.size() ? str.size() : minLength;

        int low = 1;
        int high = minLength;

        while (low <= high)
        {
            int middle = (low + high) / 2;

            if (isCommonPrefix(strs, middle))
                low = middle + 1;

            else
                high = middle - 1;
        }

        return strs[0].substr(0, (low + high) / 2);
    }

    bool isCommonPrefix(vector<string> &strs, int length)
    {
        string str1 = strs[0].substr(0, length);

        for (int i = 1; i < strs.size(); i++)
            if (!(strs[i].rfind(str1, 0) == 0))
                return false;

        return true;
    }
};