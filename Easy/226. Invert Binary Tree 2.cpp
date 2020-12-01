// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        return invertTreeRecursive(root);
    }

    TreeNode *invertTreeRecursive(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *node = new TreeNode(root->val);
        node->left = invertTreeRecursive(root->right);
        node->right = invertTreeRecursive(root->left);

        return node;
    }
};
