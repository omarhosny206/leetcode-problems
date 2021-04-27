// https://leetcode.com/problems/pancake-sorting/

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> result;

        for (int i = arr.size(); i > 0; --i)
        {
            int index = getIndex(arr, i);
            flip(arr, index);
            flip(arr, i - 1);
            result.push_back(index + 1);
            result.push_back(i);
        }

        return result;
    }

    void flip(vector<int> &arr, int index)
    {
        int i = 0;
        while (i < index)
        {
            int temp = arr[i];
            arr[i++] = arr[index];
            arr[index--] = temp;
        }
    }

    int getIndex(vector<int> &arr, int target)
    {
        for (int i = 0; i < arr.size(); ++i)
            if (arr[i] == target)
                return i;

        return -1;
    }
};