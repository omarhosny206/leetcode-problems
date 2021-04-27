// https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int result = 0;
        unordered_map<int, int> freq;
        priority_queue<int> maxHeap;
        int sum = 0;
        int half = arr.size() / 2;

        for (int num : arr)
            freq[num]++;

        for (auto pair : freq)
            maxHeap.push(pair.second);

        while (!maxHeap.empty() && sum < half)
        {
            result++;
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return result;
    }
};