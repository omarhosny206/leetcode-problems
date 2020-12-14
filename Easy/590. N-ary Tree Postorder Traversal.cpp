// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    vector<int> postorder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<Node *> nodes;
        vector<int> result;

        nodes.push_back(root);

        while (!nodes.empty())
        {
            Node *current = nodes.back();
            nodes.pop_back();

            result.push_back(current->val);

            for (Node *node : current->children)
                nodes.push_back(node);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};