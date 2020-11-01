// https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int val = root->val;
        return isUnivalTreeRecursive(root, val);
    }

    bool isUnivalTreeRecursive(TreeNode *root, int val)
    {
        if (root == nullptr)
            return true;
        if (root->val != val)
            return false;
        return isUnivalTreeRecursive(root->left, val) && isUnivalTreeRecursive(root->right, val);
    }
};