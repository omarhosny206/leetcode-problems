
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int result = INT_MIN;
        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;
        int sum = 0;
        int counter = 0;

        while (j < nums.size())
        {
            sum += nums[j];
            freq[nums[j]]++;

            if (freq[nums[j]] > 1)
                counter++;

            if (counter == 0)
                result = max(result, sum);

            else
            {
                while (i < j && counter != 0)
                {
                    if (--freq[nums[i]] >= 1)
                        counter--;

                    sum -= nums[i];
                    i++;
                }
            }

            j++;
        }

        return result;
    }
};