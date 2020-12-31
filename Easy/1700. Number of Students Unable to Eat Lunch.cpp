// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        vector<int> amount(2, 0);

        for (int prefered_sandwich : students)
            amount[prefered_sandwich]++;

        int taken = 0;

        for (int sandwich : sandwiches)
        {
            if (amount[sandwich] > 0)
                amount[sandwich]--;

            else
                break;

            taken++;
        }

        return sandwiches.size() - taken;
    }
};