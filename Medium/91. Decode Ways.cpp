// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int numDecodings(string s)
    {

        if (s.length() == 0 || s[0] == '0')
            return 0;

        vector dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= s.length(); ++i)
        {

            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));

            if (oneDigit >= 1)
                dp[i] += dp[i - 1];

            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[s.length()];
    }
};
