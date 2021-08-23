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
public:
    int closestValue(TreeNode *root, double target)
    {
        int result = root->val;

        while (root != nullptr)
        {
            if (abs(result - target) >= abs(root->val - target))
                result = root->val;

            root = (root->val > target) ? root->left : root->right;
        }

        return result;
    }
};