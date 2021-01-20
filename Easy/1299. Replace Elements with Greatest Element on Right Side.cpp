// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        if (arr.size() == 1)
            return {-1};

        int max = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;

        for (int i = arr.size() - 2; i >= 0; --i)
        {

            if (arr[i] >= max)
            {
                int temp = arr[i];
                arr[i] = max;
                max = temp;
            }

            else
                arr[i] = max;
        }

        return arr;
    }
};