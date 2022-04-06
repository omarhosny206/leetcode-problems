// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int result = 0;
        const int MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 2; ++i)
        {
            int j = i + 1;
            int k = arr.size() - 1;

            while (j < k)
            {
                int value = arr[i] + arr[j] + arr[k];

                if (value == target)
                {
                    int left = 1, right = 1;

                    while (j < k && arr[j] == arr[j + 1])
                    {
                        left++;
                        j++;
                    }

                    while (j < k && arr[k] == arr[k - 1])
                    {
                        right++;
                        k--;
                    }

                    if (j == k)
                        result = (result + left * (left - 1) / 2) % MOD;

                    else
                        result = (result + left * right) % MOD;

                    j++;
                    k--;
                }

                else if (value > target)
                    k--;

                else
                    j++;
            }
        }

        return result;
    }
};