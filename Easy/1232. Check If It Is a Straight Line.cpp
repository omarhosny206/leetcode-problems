// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        double slope = getSlope(coordinates[0], coordinates[1]);
        for (int i = 2; i < coordinates.size(); ++i)
            if (getSlope(coordinates[0], coordinates[i]) != slope)
                return false;

        return true;
    }

    double getSlope(vector<int> cordinate1, vector<int> cordinate2)
    {
        double Vx = cordinate2[0] - cordinate1[0];
        double Vy = cordinate2[1] - cordinate1[1];

        return (Vx != 0) ? (double)Vy / Vx : 1e10;
    }
};