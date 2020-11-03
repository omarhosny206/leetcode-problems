// https://leetcode.com/problems/task-scheduler/

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        unordered_map<char, int> task_map;
        for (char task : tasks)
            task_map[task]++;

        priority_queue<int> task_maxHeap;
        for (auto p : task_map)
            task_maxHeap.push(p.second);

        int cycles = 0;

        while (!task_maxHeap.empty())
        {
            vector<int> running_task;

            for (int i = 0; i < n + 1; ++i)
            {
                if (!task_maxHeap.empty())
                {
                    running_task.push_back(task_maxHeap.top() - 1);
                    task_maxHeap.pop();
                }
            }

            for (int task : running_task)
                if (task)
                    task_maxHeap.push(task);

            cycles += (task_maxHeap.empty() ? running_task.size() : n + 1);
        }

        return cycles;
    }
};