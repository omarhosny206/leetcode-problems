// https://leetcode.com/problems/relative-ranks/

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {

        if (nums.size() == 0)
            return {};

        vector<string> answer(nums.size());
        map<int, int> rank;

        int rank_val = nums.size();

        for (int i = 0; i < nums.size(); i++)
            rank[nums[i]] = 0;

        for (auto it = rank.begin(); it != rank.end(); ++it, --rank_val)
            it->second = rank_val;

        for (int i = 0; i < nums.size(); ++i)
            answer[i] = getRank(rank[nums[i]]);

        return answer;
    }

    string getRank(int key)
    {
        if (key > 3)
            return to_string(key);
        else if (key == 3)
            return "Bronze Medal";
        else if (key == 2)
            return "Silver Medal";
        else
            return "Gold Medal";
    }
};