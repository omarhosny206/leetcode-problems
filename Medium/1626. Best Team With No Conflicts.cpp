// https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        int answer = 0;
        vector<pair<int, int>> player;

        for (int i = 0; i < n; i++)
            player.push_back({-ages[i], -scores[i]});

        sort(player.begin(), player.end());

        int dp[n];
        memset(dp, 0, sizeof dp);

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; --j)
                if (-player[i].second <= -player[j].second)
                    dp[i] = max(dp[i], dp[j] - player[i].second);

            answer = max(answer, dp[i]);
        }

        return answer;
    }
};