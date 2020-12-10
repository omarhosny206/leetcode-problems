// https://leetcode.com/problems/validate-binary-tree-nodes/

class DSU
{
private:
    vector<int> parent;

public:
    DSU(int N)
    {
        for (int i = 0; i < N; ++i)
            parent.push_back(i);
    }

    int Find(int x)
    {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);

        return parent[x];
    }

    bool Union(int x, int y)
    {
        int r1 = Find(x), r2 = Find(y);

        if (r1 == r2)
            return false;

        parent[r1] = r2;

        return true;
    }

    bool checkRoot()
    {
        int root = 0;

        for (int i = 0; i < parent.size(); i++)
            if (parent[i] == i)
                root++;

        return root == 1;
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        DSU dsu = DSU(n);

        for (int i = 0; i < n; i++)
        {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1)
                if (!dsu.Union(i, left))
                    return false;

            if (right != -1)
                if (!dsu.Union(i, right))
                    return false;
        }

        return dsu.checkRoot();
    }
};