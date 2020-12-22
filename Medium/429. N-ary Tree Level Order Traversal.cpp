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
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<Node *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> row;
            int n = result.size();
            result.push_back(row);

            for (int i = 0; i < size; ++i)
            {
                Node *current = nodes.front();
                nodes.pop();
                result[n].push_back(current->val);
                for (Node *node : current->children)
                    nodes.push(node);
            }
        }

        return result;
    }
};