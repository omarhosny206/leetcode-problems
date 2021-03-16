// https://leetcode.com/problems/count-items-matching-a-rule/

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int result = 0;

        map<string, int> mapping = {
            {"type", 0},
            {"color", 1},
            {"name", 2}};

        for (int i = 0; i < items.size(); ++i)
            if (items[i][mapping[ruleKey]] == ruleValue)
                result++;

        return result;
    }
};