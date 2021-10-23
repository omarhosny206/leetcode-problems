// https://leetcode.com/problems/two-out-of-three/

class Solution
{
    vector<int> result;
    unordered_set<int> nums;
    unordered_set<int> numbers1;
    unordered_set<int> numbers2;
    unordered_set<int> numbers3;

public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        Insert(nums, nums1);
        Insert(nums, nums2);
        Insert(nums, nums3);

        Insert(numbers1, nums1);
        Insert(numbers2, nums2);
        Insert(numbers3, nums3);

        Filter();

        return result;
    }

    void Filter()
    {
        for (const int &num : nums)
        {
            int counter = 0;

            if (numbers1.find(num) != numbers1.end())
                counter++;

            if (numbers2.find(num) != numbers2.end())
                counter++;

            if (numbers3.find(num) != numbers3.end())
                counter++;

            if (counter >= 2)
                result.push_back(num);
        }
    }

    void Insert(unordered_set<int> &nums, vector<int> &givenNums)
    {
        for (int &num : givenNums)
            nums.insert(num);
    }
};