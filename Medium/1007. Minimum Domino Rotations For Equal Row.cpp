// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int result = min({getMinSwaps(tops, bottoms, tops[0]),
                          getMinSwaps(tops, bottoms, bottoms[0]),
                          getMinSwaps(bottoms, tops, tops[0]),
                          getMinSwaps(bottoms, tops, bottoms[0])});

        return result == INT_MAX ? -1 : result;
    }

    int getMinSwaps(vector<int> &first, vector<int> &second, int target)
    {
        int result = 0;

        for (int i = 0; i < first.size(); ++i)
        {
            if (first[i] != target && second[i] != target)
                return INT_MAX;

            else if (first[i] != target)
                result++;
        }

        return result;
    }
};