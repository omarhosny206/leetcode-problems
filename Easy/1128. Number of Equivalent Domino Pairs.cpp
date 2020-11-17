// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int answer = 0;

        map<vector<int>, int> mapping;

        for (vector<int> domino : dominoes)
        {
            if (domino[0] > domino[1])
                swap(domino[0], domino[1]);

            if (mapping.find(domino) != mapping.end())
                answer += mapping[domino]++;

            else
                mapping[domino]++;
        }
        return answer;
    }
};