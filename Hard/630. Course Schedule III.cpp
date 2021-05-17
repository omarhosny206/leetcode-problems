// https://leetcode.com/problems/course-schedule-iii/

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        priority_queue<int> maxHeap;
        int current = 0;
        sort(courses.begin(), courses.end(), comparator);

        for (int i = 0; i < courses.size(); i++)
        {
            current += courses[i][0];
            maxHeap.push(courses[i][0]);

            if (current > courses[i][1])
            {
                current = current - maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }

    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1]);
    }
};