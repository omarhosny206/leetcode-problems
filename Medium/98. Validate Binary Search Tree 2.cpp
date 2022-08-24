// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }

    bool dfs(TreeNode *root, long long max, long long min)
    {
        if (root == NULL)
            return true;

        if (root->val >= max || root->val <= min)
            return false;

        return dfs(root->left, (long long)root->val, min) && dfs(root->right, max, (long long)root->val);
    }
};