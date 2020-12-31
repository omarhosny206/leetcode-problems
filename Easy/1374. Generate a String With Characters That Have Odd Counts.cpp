// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution
{
public:
    string generateTheString(int n)
    {
        string result = "";

        int first = (n % 2 == 0) ? n - 1 : n;
        int second = n - first;

        while (first--)
            result += 'a';

        while (second--)
            result += 'b';

        return result;
    }
};