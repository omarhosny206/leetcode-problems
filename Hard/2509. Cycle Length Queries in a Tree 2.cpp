// https://leetcode.com/problems/cycle-length-queries-in-a-tree/

class Solution
{
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> result;

        for (vector<int> &query : queries)
        {
            int numNodes = 0;
            int firstNode = query[0];
            int secondNode = query[1];

            while (firstNode != secondNode)
            {
                numNodes++;

                if (firstNode > secondNode)
                    firstNode /= 2;

                else
                    secondNode /= 2;
            }

            result.push_back(numNodes + 1);
        }

        return result;
    }
};