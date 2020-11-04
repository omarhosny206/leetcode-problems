// https://leetcode.com/problems/balanced-binary-tree/

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
    bool result = true;

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        Height(root);
        return result;
    }

    int Height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = Height(root->left);
        int right = Height(root->right);

        if (abs(left - right) > 1)
            result = false;

        return max(left, right) + 1;
    }
};