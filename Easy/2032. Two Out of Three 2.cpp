// https://leetcode.com/problems/two-out-of-three/

class Solution
{
    vector<int> result;
    unordered_map<int, unordered_set<int>> seen;

public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        Insert(nums1, 1);
        Insert(nums2, 2);
        Insert(nums3, 3);

        Filter();

        return result;
    }

    void Filter()
    {
        for (auto &pair : seen)
            if (pair.second.size() >= 2)
                result.push_back(pair.first);
    }

    void Insert(vector<int> &givenNums, int i)
    {
        for (int &num : givenNums)
            seen[num].insert(i);
    }
};