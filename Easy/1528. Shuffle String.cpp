// https://leetcode.com/problems/shuffle-string/

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {

        string result = "";

        vector<char> temp(s.size());

        for (int i = 0; i < indices.size(); i++)
            temp[indices[i]] = s[i];

        for (char c : temp)
            result += c;

        return result;
    }
};