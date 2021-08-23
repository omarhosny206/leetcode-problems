// https://leetcode.com/accounts/login/?next=/problems/inorder-successor-in-bst/

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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *result = nullptr;

        while (root)
        {
            if (root->val > p->val)
            {
                result = root;
                root = root->left;
            }

            else
                root = root->right;
        }

        return result;
    }
};