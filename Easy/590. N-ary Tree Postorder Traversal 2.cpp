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
    vector<int> result;

public:
    vector<int> postorder(Node *root)
    {

        if (root != nullptr)
        {
            for (Node *node : root->children)
                postorder(node);

            result.push_back(root->val);
        }

        return result;
    }
};