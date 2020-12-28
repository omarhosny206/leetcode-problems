// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int result = arr[0];
        int counter = 1;

        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] != arr[i - 1])
            {
                if (counter > arr.size() / 4)
                    return arr[i - 1];

                counter = 1;
            }
            else
                counter++;
        }

        return arr[arr.size() - 1];
    }
};