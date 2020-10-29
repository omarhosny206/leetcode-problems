// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode *root)
    {
        int max_depth = maxDepth_helper(root, 0);
        return max_depth;
    }

    int maxDepth_helper(TreeNode *root, int max_depth)
    {

        if (root == nullptr)
            return max_depth;

        max_depth += 1;

        return max(maxDepth_helper(root->left, max_depth), maxDepth_helper(root->right, max_depth));
    }
};