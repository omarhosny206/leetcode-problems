// https://leetcode.com/problems/third-maximum-number/

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> uniqueNumbers;
        for (int num : nums)
            uniqueNumbers.insert(num);

        priority_queue<int> numbers_maxHeap;
        for (int num : uniqueNumbers)
            numbers_maxHeap.push(num);

        if (numbers_maxHeap.size() < 3)
            return numbers_maxHeap.top();

        int k = 2;
        while (k--)
            numbers_maxHeap.pop();

        return numbers_maxHeap.top();
    }
};