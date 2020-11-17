// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        sort(pairs.begin(), pairs.end(), cmp);
        int i = 0;
        int j = 1;
        int answer = 1;

        while (j < pairs.size())
        {
            if (pairs[i][1] < pairs[j][0])
            {
                i = j;
                answer++;
            }
            j++;
        }
        return answer;
    }

    static bool cmp(vector<int> pair1, vector<int> pair2)
    {
        return pair1[1] < pair2[1];
    }
};