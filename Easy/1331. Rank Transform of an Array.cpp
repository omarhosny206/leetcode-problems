// https://leetcode.com/problems/rank-transform-of-an-array/

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> result;
        map<int, int> numbersRank;

        for (int num : arr)
            numbersRank[num] = 0;

        int rank = 1;
        for (auto &pair : numbersRank)
        {
            pair.second += rank;
            rank++;
        }

        for (int num : arr)
            result.push_back(numbersRank[num]);

        return result;
    }
};