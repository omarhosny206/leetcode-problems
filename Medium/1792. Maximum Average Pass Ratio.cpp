// https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        double answer = 0.0;
        priority_queue<pair<double, int>> maxHeap;

        for (int i = 0; i < classes.size(); ++i)
        {
            double pass = classes[i][0];
            double total = classes[i][1];
            double delta = ((pass + 1) / (total + 1)) - ((pass / total));
            maxHeap.push({delta, i});
        }

        while (extraStudents--)
        {
            int classIndex = maxHeap.top().second;
            classes[classIndex][0]++;
            classes[classIndex][1]++;
            double pass = classes[classIndex][0];
            double total = classes[classIndex][1];
            double newDelta = ((pass + 1) / (total + 1)) - ((pass / total));
            maxHeap.pop();
            maxHeap.push({newDelta, classIndex});
        }

        for (int i = 0; i < classes.size(); ++i)
            answer += (double)classes[i][0] / (double)classes[i][1];

        return answer / classes.size();
    }
};