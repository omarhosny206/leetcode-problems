// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};

        bfs(root);
        return result;
    }

    void bfs(Node *root)
    {
        queue<Node *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            result.push_back({});

            for (int i = 0; i < size; ++i)
            {
                Node *current = nodes.front();
                nodes.pop();

                result[result.size() - 1].push_back(current->val);

                for (Node *node : current->children)
                    nodes.push(node);
            }
        }
    }
};