// https://leetcode.com/problems/the-k-strongest-values-in-an-array/

class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        vector<int> result;
        int i = 0;
        int j = arr.size() - 1;

        sort(arr.begin(), arr.end());
        int median = arr[(arr.size() - 1) / 2];

        while (k--)
        {
            if (abs(arr[i] - median) > abs(arr[j] - median))
            {
                result.push_back(arr[i]);
                i++;
            }

            else
            {
                result.push_back(arr[j]);
                j--;
            }
        }

        return result;
    }
};