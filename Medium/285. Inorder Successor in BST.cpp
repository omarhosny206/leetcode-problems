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
    TreeNode *result;

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        result = nullptr;
        bool found = false;

        DFS(root, p, found);

        return result;
    }

    void DFS(TreeNode *root, TreeNode *p, bool &found)
    {
        if (root == nullptr)
            return;

        DFS(root->left, p, found);

        if (found)
        {
            result = root;
            found = false;
            return;
        }

        if (root->val == p->val)
            found = true;

        DFS(root->right, p, found);
    }
};