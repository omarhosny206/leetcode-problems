// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> result;

        if (arr.size() == 1)
            return {-1};

        for (int i = 0; i < arr.size(); ++i)
        {
            int max = -1;
            for (int j = i + 1; j < arr.size(); ++j)
                if (max < arr[j])
                    max = arr[j];

            result.push_back(max);
        }

        return result;
    }
};