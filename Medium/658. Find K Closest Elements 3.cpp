// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> result;
        int minDifference = INT_MAX;
        int index = -1;

        for (int i = 0; i < arr.size(); ++i)
        {
            if (abs(arr[i] - x) < minDifference)
            {
                minDifference = abs(arr[i] - x);
                index = i;
            }
        }

        result.push_back(arr[index]);
        k--;
        int i = index - 1;
        int j = index + 1;

        while (k > 0 && i >= 0 && j < arr.size())
        {
            int left = abs(arr[i] - x);
            int right = abs(arr[j] - x);

            if (left <= right)
            {
                result.push_back(arr[i]);
                i--;
            }
            else
            {
                result.push_back(arr[j]);
                j++;
            }
            k--;
        }

        while (k > 0 && i >= 0)
        {
            int left = abs(arr[i] - x);
            result.push_back(arr[i]);
            i--;
            k--;
        }

        while (k > 0 && j < arr.size())
        {
            int right = abs(arr[j] - x);
            result.push_back(arr[j]);
            j++;
            k--;
        }

        sort(result.begin(), result.end());
        return result;
    }
};