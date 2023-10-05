// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> result(arr.size());
        int maxFromRight = -1;

        for (int i = arr.size() - 1; i >= 0; --i)
        {
            result[i] = maxFromRight;
            maxFromRight = max(maxFromRight, arr[i]);
        }

        return result;
    }
};