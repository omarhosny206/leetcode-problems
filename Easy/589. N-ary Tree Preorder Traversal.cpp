// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<int> result;
        stack<Node *> nodes;

        nodes.push(root);

        while (!nodes.empty())
        {
            Node *current = nodes.top();
            nodes.pop();

            if (current == nullptr)
                continue;

            result.push_back(current->val);

            for (auto node = current->children.rbegin(); node != current->children.rend(); node++)
                nodes.push(*node);
        }

        return result;
    }
};