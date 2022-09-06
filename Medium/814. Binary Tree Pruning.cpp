// https://leetcode.com/problems/binary-tree-pruning/

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
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        return dfs(root) ? root : nullptr;
    }

    bool dfs(TreeNode *root)
    {
        if (root == nullptr)
            return false;

        bool left = dfs(root->left);
        bool right = dfs(root->right);

        if (left == false)
            root->left = nullptr;

        if (right == false)
            root->right = nullptr;

        return root->val == 1 || left || right;
    }
};