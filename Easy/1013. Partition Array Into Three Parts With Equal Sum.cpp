// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int counter = 0;
        int sum = 0;
        int currentSum = 0;

        for (int i = 0; i < arr.size(); ++i)
            sum += arr[i];

        if (sum % 3 == 0)
        {
            for (int i = 0; i < arr.size(); ++i)
            {
                currentSum += arr[i];
                if (currentSum == sum / 3)
                {
                    counter++;
                    currentSum = 0;
                }
            }
        }

        return counter >= 3;
    }
};