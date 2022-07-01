
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int result = 0;

        sort(boxTypes.begin(), boxTypes.end(), compare);

        for (int i = 0; i < boxTypes.size(); ++i)
        {
            if (boxTypes[i][0] <= truckSize)
            {
                result += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];

                if (truckSize == 0)
                    return result;
            }

            else
                return result + (truckSize * boxTypes[i][1]);
        }

        return result;
    }

    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
};