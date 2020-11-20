// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameter = 1;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return diameter - 1;
    }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        diameter = max(diameter, left + right + 1);
        return max(left, right) + 1;
    }
};