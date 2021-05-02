// https://leetcode.com/problems/largest-values-from-labels/

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        int result = 0;
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> freq;
        int counter = 0;

        for (int i = 0; i < values.size(); ++i)
            maxHeap.push({values[i], labels[i]});

        while (!maxHeap.empty() && counter < num_wanted)
        {
            int value = maxHeap.top().first;
            int label = maxHeap.top().second;
            maxHeap.pop();

            if (freq[label] < use_limit)
            {
                result += value;
                counter++;
            }

            freq[label]++;
        }

        return result;
    }
};