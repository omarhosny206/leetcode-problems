// https://leetcode.com/problems/validate-binary-tree-nodes/

class DSU
{
private:
    vector<int> parent;

public:
    DSU(int size)
    {
        parent = vector<int>(size);

        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    void Union(int source, int destination)
    {
        parent[destination] = source;
    }

    int find(int node)
    {
        if (parent[node] == node)
            return node;

        parent[node] = find(parent[node]);
        return parent[node];
    }

    bool hasOnlyOneRoot()
    {
        int rootsCounter = 0;

        for (int i = 0; i < parent.size(); ++i)
            if (parent[i] == i)
                rootsCounter++;

        return rootsCounter == 1;
    }
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        DSU *dsu = new DSU(n);

        for (int i = 0; i < leftChild.size(); ++i)
        {
            int rootNodeParent = dsu->find(i);

            if (leftChild[i] != -1)
            {
                int leftNodeParent = dsu->find(leftChild[i]);

                if (rootNodeParent == leftNodeParent || leftNodeParent != leftChild[i])
                    return false;

                dsu->Union(rootNodeParent, leftNodeParent);
            }

            if (rightChild[i] != -1)
            {
                int rightNodeParent = dsu->find(rightChild[i]);

                if (rootNodeParent == rightNodeParent || rightNodeParent != rightChild[i])
                    return false;

                dsu->Union(rootNodeParent, rightNodeParent);
            }
        }

        return dsu->hasOnlyOneRoot();
    }
};