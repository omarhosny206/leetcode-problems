// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;
        map<int, int> mapping;

        for (int n : nums)
            mapping[n]++;

        int previousOccurence = 0;

        for (auto &p : mapping)
        {
            int currentOccurence = p.second;
            p.second = previousOccurence;
            previousOccurence += currentOccurence;
        }

        for (int n : nums)
            result.push_back(mapping[n]);
        return result;
    }
};