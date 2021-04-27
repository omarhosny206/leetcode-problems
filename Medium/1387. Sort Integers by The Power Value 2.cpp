// https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = lo; i <= hi; ++i)
            minHeap.push({getPower(i), i});

        while (--k)
            minHeap.pop();

        return minHeap.top().second;
    }

    int getPower(int num)
    {
        int power = 0;

        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;

            else
                num = (3 * num) + 1;

            power++;
        }

        return power;
    }
};