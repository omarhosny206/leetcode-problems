// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        return searchBST_Helper(root, val);
    }

    TreeNode *searchBST_Helper(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == val)
            return root;

        else if (root->val > val)
            return searchBST_Helper(root->left, val);

        return searchBST_Helper(root->right, val);
    }
};