class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> result(2 * n);

        int i = 0;
        int j = n;
        int index = 0;

        while (i < n)
        {
            result[index] = nums[i];
            result[index + 1] = nums[j];

            i++;
            j++;
            index += 2;
        }

        return result;
    }
};