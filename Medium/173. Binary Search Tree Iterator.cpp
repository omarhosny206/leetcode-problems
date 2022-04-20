// https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
    stack<TreeNode *> nodes;

public:
    BSTIterator(TreeNode *root)
    {
        getLeftSubtree(root);
    }

    int next()
    {
        TreeNode *node = nodes.top();
        nodes.pop();

        getLeftSubtree(node->right);

        return node->val;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }

    void getLeftSubtree(TreeNode *root)
    {
        while (root != nullptr)
        {
            nodes.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */