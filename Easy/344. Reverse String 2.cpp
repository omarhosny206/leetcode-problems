// https://leetcode.com/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        Reverse(s, 0, s.size() - 1);
    }

    void Reverse(vector<char> &s, int i, int j)
    {
        if (i > j)
            return;

        Reverse(s, i + 1, j - 1);
        Swap(s, i, j);
    }

    void Swap(vector<char> &s, int i, int j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
};