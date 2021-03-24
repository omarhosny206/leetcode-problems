// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight)
            return root;

        if (leftHeight > rightHeight)
            return subtreeWithAllDeepest(root->left);

        return subtreeWithAllDeepest(root->right);
    }

    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};