// https://leetcode.com/problems/corporate-flight-bookings/

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> result(n);

        for (vector<int> &booking : bookings)
        {
            int first = booking[0] - 1;
            int last = booking[1] - 1;
            int seats = booking[2];

            result[first] += seats;

            if (last + 1 < n)
                result[last + 1] -= seats;
        }

        for (int i = 1; i < n; ++i)
            result[i] += result[i - 1];

        return result;
    }
};