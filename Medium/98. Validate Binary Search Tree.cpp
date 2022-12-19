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
        int left = dfs(root->left, LLONG_MIN, root->val);
        int right = dfs(root->right, root->val, LLONG_MAX);

        return left && right;
    }

    bool dfs(TreeNode *root, long long minValue, long long maxValue)
    {
        if (root == nullptr)
            return true;

        if (root->val <= minValue || root->val >= maxValue)
            return false;

        bool left = dfs(root->left, minValue, root->val);
        bool right = dfs(root->right, root->val, maxValue);

        return left && right;
    }
};