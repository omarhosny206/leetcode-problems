// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return lowestCommonAncestorRecursive(root, p, q);
    }

    TreeNode *lowestCommonAncestorRecursive(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestorRecursive(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestorRecursive(root->right, p, q);
        return root;
    }
};