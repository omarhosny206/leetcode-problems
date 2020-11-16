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
        treeTraversal(root);
    }

    int next()
    {
        TreeNode *top = nodes.top();
        nodes.pop();
        return top->val;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }

    void treeTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        treeTraversal(root->right);
        nodes.push(root);
        treeTraversal(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */