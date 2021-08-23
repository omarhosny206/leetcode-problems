// https://leetcode.com/problems/closest-binary-search-tree-value/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution
{
    int result;

public:
    int closestValue(TreeNode *root, double target)
    {
        result = root->val;
        DFS(root, target);
        return result;
    }

    void DFS(TreeNode *root, double target)
    {
        if (root == nullptr)
            return;

        if (abs(result - target) >= abs(root->val - target))
            result = root->val;

        (root->val > target) ? DFS(root->left, target) : DFS(root->right, target);
    }
};