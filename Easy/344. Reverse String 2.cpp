// https://leetcode.com/problems/reverse-string/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s, 0, s.size() - 1);
    }

    void reverse(vector<char> &letters, int i, int j)
    {
        if (i > j)
            return;

        reverse(letters, i + 1, j - 1);
        swap(letters, i, j);
    }

    void swap(vector<char> &letters, int i, int j)
    {
        char temp = letters[i];
        letters[i] = letters[j];
        letters[j] = temp;
    }
};