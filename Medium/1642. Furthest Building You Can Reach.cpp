// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int usedBricks = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < heights.size() - 1; ++i)
        {
            int height = heights[i + 1] - heights[i];

            if (height < 0)
                continue;

            min_heap.push(height);

            if (min_heap.size() > ladders)
            {
                usedBricks += min_heap.top();
                min_heap.pop();
            
                if (usedBricks > bricks)
                    return i;
            }
        }
        
        return heights.size() - 1;
    }
};