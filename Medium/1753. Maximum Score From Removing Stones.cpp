// https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        int result = 0;
        priority_queue<int> maxHeap;

        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        while (maxHeap.size() >= 2)
        {
            int firstPile = maxHeap.top();
            maxHeap.pop();

            int secondPile = maxHeap.top();
            maxHeap.pop();

            firstPile--;
            secondPile--;
            result++;

            if (firstPile > 0)
                maxHeap.push(firstPile);

            if (secondPile > 0)
                maxHeap.push(secondPile);
        }

        return result;
    }
};