// https://leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> stones_max_heap;
        for (int stone : stones)
            stones_max_heap.push(stone);

        while (!stones_max_heap.empty())
        {
            int stone_y = stones_max_heap.top();
            stones_max_heap.pop();

            if (stones_max_heap.empty())
                return stone_y;

            int stone_x = stones_max_heap.top();
            stones_max_heap.pop();

            if (stone_y - stone_x != 0)
                stones_max_heap.push(stone_y - stone_x);
        }
        return 0;
    }
};