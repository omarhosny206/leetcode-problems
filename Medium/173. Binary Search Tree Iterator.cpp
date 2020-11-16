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
    queue<TreeNode *> nodes;

public:
    BSTIterator(TreeNode *root)
    {
        inOrder(root);
    }

    int next()
    {
        TreeNode *top = nodes.front();
        nodes.pop();
        return top->val;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        nodes.push(root);
        inOrder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */