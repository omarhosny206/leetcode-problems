// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        convertBSTRecursive(root);
        return root;
    }

    void convertBSTRecursive(TreeNode *root)
    {

        if (root == nullptr)
            return;
        convertBSTRecursive(root->right);
        root->val += sum;
        sum = root->val;
        convertBSTRecursive(root->left);
    }
};