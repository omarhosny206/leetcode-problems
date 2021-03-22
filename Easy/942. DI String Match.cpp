// https://leetcode.com/problems/di-string-match/

class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        vector<int> result;
        int i = 0, j = S.size();

        for (char c : S)
            result.push_back(c == 'I' ? i++ : j--);

        result.push_back(j);
        return result;
    }
};