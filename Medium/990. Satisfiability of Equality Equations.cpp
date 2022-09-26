// https://leetcode.com/problems/satisfiability-of-equality-equations/

class DSU
{
    vector<int> parent;

public:
    DSU()
    {
        parent = vector<int>(26);

        for (int i = 0; i < 26; ++i)
            parent[i] = i;
    }

    int find(int node)
    {
        if (parent[node] == node)
            return node;

        parent[node] = find(parent[node]);
        return parent[node];
    }

    void Union(int &leftNode, int &rightNode)
    {
        parent[rightNode] = parent[leftNode];
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU *dsu = new DSU;

        for (string &equation : equations)
        {
            char left = equation[0];
            char right = equation[3];
            char operation = equation[1];

            if (operation == '=')
            {
                int leftParent = dsu->find(left - 'a');
                int rightParent = dsu->find(right - 'a');
                dsu->Union(leftParent, rightParent);
            }
        }

        for (string &equation : equations)
        {
            char left = equation[0];
            char right = equation[3];
            char operation = equation[1];

            int leftParent = dsu->find(left - 'a');
            int rightParent = dsu->find(right - 'a');

            if (operation == '!' && leftParent == rightParent)
                return false;
        }

        return true;
    }
};