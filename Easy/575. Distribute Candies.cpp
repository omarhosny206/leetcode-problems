// https://leetcode.com/problems/distribute-candies/

class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        unordered_set<int> differentCandies;
        for (int candy : candies)
            differentCandies.insert(candy);
        int answer = min(differentCandies.size(), candies.size() / 2);
        return answer;
    }
};