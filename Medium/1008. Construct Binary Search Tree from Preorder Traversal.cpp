// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int pos = 0;
        TreeNode *root = bstFromPreorder_Helper(preorder, pos, INT_MAX);
        return root;
    }

    TreeNode *bstFromPreorder_Helper(vector<int> &preorder, int &pos, int limit)
    {
        if (pos >= preorder.size() || preorder[pos] > limit)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pos]);
        pos++;
        root->left = bstFromPreorder_Helper(preorder, pos, root->val);
        root->right = bstFromPreorder_Helper(preorder, pos, limit);
        return root;
    }
};