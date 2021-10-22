// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int result = 0;

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (int i = 0; i < seats.size(); ++i)
            result += abs(seats[i] - students[i]);

        return result;
    }
};