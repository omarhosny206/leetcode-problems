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
    stack<int> nodes;

public:
    BSTIterator(TreeNode *root)
    {
        dfs(root);
    }

    int next()
    {
        int node = nodes.top();
        nodes.pop();

        return node;
    }

    bool hasNext()
    {
        return !nodes.empty();
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->right);
        nodes.push(root->val);
        dfs(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */