// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution
{
    vector<vector<int>> result;
    unordered_set<int> firstSeen;
    unordered_set<int> secondSeen;

public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        result = vector<vector<int>>(2);

        for (int &num : nums1)
            firstSeen.insert(num);

        for (int &num : nums2)
            secondSeen.insert(num);

        insertFirstDistinctNumbers();
        insertSecondDistinctNumbers();

        return result;
    }

    void insertFirstDistinctNumbers()
    {
        for (const int &num : firstSeen)
            if (secondSeen.find(num) == secondSeen.end())
                result[0].push_back(num);
    }

    void insertSecondDistinctNumbers()
    {
        for (const int &num : secondSeen)
            if (firstSeen.find(num) == firstSeen.end())
                result[1].push_back(num);
    }
};