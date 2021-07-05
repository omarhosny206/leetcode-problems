// https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int result = 0;
        int i = 0;
        int j = 0;

        while (j < seats.size())
        {
            if (seats[j] == 1)
            {

                result = max(result, evaluateDistance(seats, i, j));
                i = j;
            }

            j++;
        }

        j--;
        result = max(result, evaluateDistance(seats, i, j));

        return result;
    }

    int evaluateDistance(vector<int> &seats, int &i, int &j)
    {
        if (seats[i] == 0 || seats[j] == 0)
            return j - i;

        return (j - i) / 2;
    }
};