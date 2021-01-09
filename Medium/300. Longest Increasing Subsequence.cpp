// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> list;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] > list[list.size() - 1])
                list.push_back(nums[i]);
            else
            {
                int index = binarySearch(list, nums[i]);
                list[index] = nums[i];
            }
        }

        return list.size();
    }

    int binarySearch(vector<int> &list, int num)
    {
        int i = 0;
        int j = list.size() - 1;
        int answer = 0;

        while (i <= j)
        {
            int middle = i + (j - i) / 2;

            if (list[middle] == num)
                return middle;

            else if (num > list[middle])
                i = middle + 1;

            else
            {
                answer = middle;
                j = middle - 1;
            }
        }
        return answer;
    }
};