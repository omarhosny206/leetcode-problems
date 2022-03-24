// https://leetcode.com/problems/boats-to-save-people/

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int result = 0;
        int i = 0;
        int j = people.size() - 1;

        people = countSort(people, limit);

        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
                j--;
            }

            else
                j--;

            result++;
        }

        return result;
    }

    vector<int> countSort(vector<int> &nums, int maxNumber)
    {
        vector<int> result(nums.size());
        vector<int> freq(maxNumber + 1);
        int index = 0;

        for (int &num : nums)
            freq[num]++;

        for (int i = 0; i < freq.size(); ++i)
            while (freq[i]--)
                result[index++] = i;

        return result;
    }
};