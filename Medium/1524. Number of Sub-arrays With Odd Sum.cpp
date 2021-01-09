// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        long answer = 0;
        int odd = 0;
        int even = 0;

        for (int num : arr)
        {
            if (num % 2 == 0)
                even++;

            else
            {
                long temp = even;
                even = odd;
                odd = temp;
                odd++;
            }
            answer += odd;
        }
        return (int)(fmod(answer, (pow(10, 9) + 7)));
    }
};