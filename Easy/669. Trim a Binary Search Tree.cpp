// https://leetcode.com/problems/trim-a-binary-search-tree/

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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        return trimBST_Helper(root, low, high);
    }

    TreeNode *trimBST_Helper(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > high)
            return trimBST_Helper(root->left, low, high);
        if (root->val < low)
            return trimBST_Helper(root->right, low, high);

        root->left = trimBST_Helper(root->left, low, high);
        root->right = trimBST_Helper(root->right, low, high);

        return root;
    }
};