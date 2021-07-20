// https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int numLines = 1;
        int currentWidth = 0;

        for (int i = 0; i < S.length(); ++i)
        {
            if (currentWidth + widths[S[i] - 'a'] <= 100)
                currentWidth += widths[S[i] - 'a'];

            else
            {
                numLines++;
                currentWidth = widths[S[i] - 'a'];
            }
        }

        return {numLines, currentWidth};
    }
};