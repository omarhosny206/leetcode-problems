// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> result(arr.size());
        int maxFromRight = -1;
        int temp;

        for (int i = arr.size() - 1; i >= 0; --i)
        {
            temp = arr[i];
            arr[i] = maxFromRight;
            maxFromRight = max(maxFromRight, temp);
        }

        return arr;
    }
};