// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> result(k);
        int left = 0;
        int right = arr.size() - 1;

        while (right - left + 1 > k)
        {
            if (abs(arr[right] - x) >= abs(arr[left] - x))
                right--;

            else
                left++;
        }

        result = vector<int>(arr.begin() + left, arr.begin() + right + 1);
        return result;
    }
};