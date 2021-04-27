// https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = lo; i <= hi; ++i)
            minHeap.push({getPower(i, 0), i});

        while (--k)
            minHeap.pop();

        return minHeap.top().second;
    }

    int getPower(int num, int power)
    {
        if (num == 1)
            return power;

        if (num % 2 == 0)
            return getPower(num / 2, power + 1);

        return getPower((3 * num) + 1, power + 1);
    }
};