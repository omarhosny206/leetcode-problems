// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode *previous = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;

public:
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        swap(first->val, second->val);
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (previous != nullptr && previous->val > root->val)
        {
            if (first == nullptr)
                first = previous;

            second = root;
        }

        previous = root;

        dfs(root->right);
    }
};