// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *root, int current)
    {
        if (root == nullptr)
            return 0;

        current ^= 1 << root->val;

        if (!root->left && !root->right)
            return ((current & (current - 1)) == 0) ? 1 : 0;

        return dfs(root->left, current) + dfs(root->right, current);
    }
};