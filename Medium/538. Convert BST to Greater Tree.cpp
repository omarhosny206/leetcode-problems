// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->right);

        root->val += sum;
        sum = root->val;

        dfs(root->left);
    }
};