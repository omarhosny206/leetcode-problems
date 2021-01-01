// https://leetcode.com/problems/positions-of-large-groups/

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        if (s.length() < 3)
            return {};

        vector<vector<int>> result;
        int start = 0;
        int end = 0;
        int i = 1;

        while (i < s.length())
        {
            if (s[i] != s[i - 1])
            {
                if (end - start + 1 >= 3)
                    result.push_back({start, end});

                start = i;
                end = i;
            }

            else
                end++;

            i++;
        }

        if (end - start + 1 >= 3)
            result.push_back({start, end});

        return result;
    }
};