// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    int max_depth = 0;

public:
    int maxDepth(Node *root)
    {
        Depth(root, 1);
        return max_depth;
    }

    void Depth(Node *root, int currentDepth)
    {
        if (root == nullptr)
            return;

        max_depth = max(max_depth, currentDepth);

        for (auto node : root->children)
            Depth(node, currentDepth + 1);
    }
};