// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        double sum = 0.0;
        int counter = 0;
        int size = arr.size();
        int start = size * .05;
        int end = size - start - 1;

        sort(arr.begin(), arr.end());

        while (start <= end)
        {
            sum += arr[start];
            counter++;
            start++;
        }

        return sum / counter;
    }
};