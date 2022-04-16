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
    int postfixSum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        return dfs(root);
    }

    TreeNode *dfs(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        root->right = dfs(root->right);

        root->val += postfixSum;
        postfixSum = root->val;

        root->left = dfs(root->left);

        return root;
    }
};