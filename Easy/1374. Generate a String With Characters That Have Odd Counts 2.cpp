// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution
{
public:
    string generateTheString(int n)
    {
        return (n % 2 == 0) ? string(n - 1, 'a') + string(1, 'b') : string(n, 'a');
    }
};