// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        queue<int> bfs;
        int answer = 0;
        bfs.push(id);

        while (!bfs.empty())
        {
            int id_x = bfs.front();
            bfs.pop();
            for (Employee *emp : employees)
            {
                if (emp->id == id_x)
                {
                    answer += emp->importance;
                    for (int e : emp->subordinates)
                        bfs.push(e);
                }
            }
        }

        return answer;
    }
};