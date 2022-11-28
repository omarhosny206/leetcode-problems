// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> result(2);
        unordered_map<int, int> lostMatches;
        unordered_set<int> winners;

        for (vector<int> &match : matches)
        {
            winners.insert(match[0]);
            lostMatches[match[1]]++;
        }

        for (const int &winner : winners)
            if (lostMatches[winner] == 0)
                result[0].push_back(winner);

        for (auto &[player, numLostMatches] : lostMatches)
            if (numLostMatches == 1)
                result[1].push_back(player);

        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());

        return result;
    }
};