// https://leetcode.com/problems/height-checker/

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int counter = 0;

        multiset<int> heights_set;

        for (int i = 0; i < heights.size(); i++)
            heights_set.insert(heights[i]);

        int i = 0;
        for (auto height : heights_set)
            if (heights[i++] != height)
                counter++;

        return counter;
    }
};