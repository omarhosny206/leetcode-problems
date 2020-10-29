// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int size = salary.size();
        double minimum = INT_MAX;
        double maximum = INT_MIN;
        double sum = 0;

        for (int n : salary)
        {
            if (minimum > n)
                minimum = n;
            if (maximum < n)
                maximum = n;
            sum += n;
        }
        return ((sum - (minimum + maximum)) / (size - 2));
    }
};