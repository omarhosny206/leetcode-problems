// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution
{
    vector<string> result;

public:
    string getHappyString(int n, int k)
    {
        string current = "";
        DFS(n, current);

        sort(result.begin(), result.end());

        if (k > result.size())
            return "";

        return result[k - 1];
    }

    void DFS(int n, string current)
    {
        if (current.length() == n)
        {
            result.push_back(current);
            return;
        }

        for (char i = 'a'; i <= 'c'; ++i)
        {
            if (current.length() == 0 || i != current.back())
            {
                current.push_back(i);
                DFS(n, current);
                current.pop_back();
            }
        }
    }
};