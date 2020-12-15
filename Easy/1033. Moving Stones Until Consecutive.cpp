// https : //leetcode.com/problems/moving-stones-until-consecutive/

class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        int min = 0;
        int max = 0;

        reSort(a, b, c);

        max = (c - b - 1) + (b - a - 1);

        if (abs(c - b) == 2 || abs(b - a) == 2)
            min = 1;

        else
        {
            if (a < b - 1)
                min++;

            if (b < c - 1)
                min++;
        }

        return {min, max};
    }

    void reSort(int &a, int &b, int &c)
    {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
    }
};