// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int result = countSubarrays(nums, k) - countSubarrays(nums, k - 1);
        return result;
    }

    int countSubarrays(vector<int> &nums, int k)
    {
        int result = 0;
        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < nums.size())
        {
            if (isOdd(nums[j]))
                counter++;

            while (i <= j && counter > k)
            {
                if (isOdd(nums[i]))
                    counter--;

                i++;
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }

    bool isOdd(int num)
    {
        return num % 2 == 1;
    }
};