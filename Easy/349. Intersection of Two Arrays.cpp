// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_set<int> numbers;
        unordered_set<int> intersection;

        for (int n : nums1)
            numbers.insert(n);

        for (int n : nums2)
            if (numbers.find(n) != numbers.end())
                intersection.insert(n);

        for (int n : intersection)
            result.push_back(n);

        return result;
    }
};