// https://leetcode.com/problems/groups-of-special-equivalent-strings/

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_set<string> seen;

        for (string s : A)
        {
            string even = "";
            string odd = "";

            for (int i = 0; i < s.length(); ++i)
            {
                if (i % 2 == 0)
                    even += s[i];
                else
                    odd += s[i];
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            seen.insert(even + odd);
        }

        return seen.size();
    }
};