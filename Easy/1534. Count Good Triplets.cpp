// https://leetcode.com/problems/count-good-triplets/

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int length = arr.size();
        int answer = 0;

        if (length < 3)
            return 0;

        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                    for (int k = j + 1; k < length; k++)
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            answer++;
            }
        }
        return answer;
    }
};