// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];

            if (sum == target)
                return {i + 1, j + 1};

            else if (sum > target)
            {
                int num = numbers[j];
                
                while (num == numbers[j])
                    j--;
            }

            else if (sum < target)
            {
                int num = numbers[i];

                while (num == numbers[i])
                    i++;
            }
        }
        
        return {};
    }
};