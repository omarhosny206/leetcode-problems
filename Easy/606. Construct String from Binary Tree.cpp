// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode *root)
    {
        return dfs(root);
    }

    string dfs(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        if (root->left == nullptr && root->right == nullptr)
            return to_string(root->val);

        if (root->right == nullptr)
            return to_string(root->val) + "(" + dfs(root->left) + ")";

        return to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    }
};