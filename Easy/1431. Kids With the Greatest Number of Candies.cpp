// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result(candies.size(), false);
        int maximum = INT_MIN;
        int i = 0;

        for (int candy : candies)
            maximum = max(maximum, candy);

        for (int candy : candies)
        {
            if (candy + extraCandies >= maximum)
                result[i] = true;
            i++;
        }

        return result;
    }
};