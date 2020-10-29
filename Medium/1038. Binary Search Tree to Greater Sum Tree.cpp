// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    int sum;

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        bstToGstRecursive(root);
        return root;
    }

    void bstToGstRecursive(TreeNode *root)
    {

        if (root == nullptr)
            return;

        bstToGstRecursive(root->right);
        root->val += sum;
        sum = root->val;
        bstToGstRecursive(root->left);
    }
};