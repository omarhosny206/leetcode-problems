// https://leetcode.com/problems/determine-color-of-a-chessboard-square/

class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        bool first = ((coordinates[0] - 'a') + 1) % 2 == 0 ? true : false;
        bool second = (coordinates[1] - '0') % 2 == 0 ? true : false;
        return first != second;
    }
};