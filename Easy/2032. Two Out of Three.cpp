// https://leetcode.com/problems/two-out-of-three/

class Solution
{
    vector<int> result;
    unordered_map<int, int> freq;
    unordered_set<int> numbers1;
    unordered_set<int> numbers2;
    unordered_set<int> numbers3;

public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        Insert(numbers1, nums1);
        Insert(numbers2, nums2);
        Insert(numbers3, nums3);

        countFreq(numbers1);
        countFreq(numbers2);
        countFreq(numbers3);

        Filter();

        return result;
    }

    void Filter()
    {
        for (auto &pair : freq)
            if (pair.second >= 2)
                result.push_back(pair.first);
    }

    void countFreq(unordered_set<int> &nums)
    {
        for (const int &num : nums)
            freq[num]++;
    }

    void Insert(unordered_set<int> &nums, vector<int> &givenNums)
    {
        for (int &num : givenNums)
            nums.insert(num);
    }
};