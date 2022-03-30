// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution
{
    vector<vector<int>> result;
    unordered_set<int> firstValues;
    unordered_set<int> secondValues;

public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        result = vector<vector<int>>(2);

        for (int &num : nums1)
            firstValues.insert(num);

        for (int &num : nums2)
            secondValues.insert(num);

        insertFirstDistinctValues();
        insertSecondDistinctValues();

        return result;
    }

    void insertFirstDistinctValues()
    {
        for (const int &num : firstValues)
            if (secondValues.find(num) == secondValues.end())
                result[0].push_back(num);
    }

    void insertSecondDistinctValues()
    {
        for (const int &num : secondValues)
            if (firstValues.find(num) == firstValues.end())
                result[1].push_back(num);
    }
};