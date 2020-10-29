// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST_Recursively(root, LLONG_MAX, LLONG_MIN);
    }

    bool isValidBST_Recursively(TreeNode *root, int64_t max, int64_t min)
    {

        if (root == NULL)
            return true;

        else if (root->val >= max || root->val <= min)
            return false;

        else
            return isValidBST_Recursively(root->left, int64_t(root->val), min) && isValidBST_Recursively(root->right, max, int64_t(root->val));
    }
};