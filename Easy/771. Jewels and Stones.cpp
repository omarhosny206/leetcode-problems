//https://leetcode.com/problems/jewels-and-stones/submissions/

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {

        int numJewels = 0;

        unordered_set<char> jewels;

        for (char c : J)
            jewels.insert(c);

        for (char c : S)
            if (jewels.find(c) != jewels.end())
                numJewels++;

        return numJewels;
    }
};