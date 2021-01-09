// https://leetcode.com/problems/average-waiting-time/

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double waitingTime = 0;
        int chefStartTime = customers[0][0];

        for (int i = 0; i < customers.size(); ++i)
        {
            int customerArrivalTime = customers[i][0];
            int dishPreparingTime = customers[i][1];
            chefStartTime = max(chefStartTime, customerArrivalTime);
            waitingTime += chefStartTime - customerArrivalTime + dishPreparingTime;
            chefStartTime += dishPreparingTime;
        }

        return waitingTime / customers.size();
    }
};