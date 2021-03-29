// https://leetcode.com/problems/construct-the-rectangle/

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int number = sqrt(area);

        if (number * number == area)
            return {number, number};

        while (area % number != 0)
            number--;

        return {area / number, number};
    }
};