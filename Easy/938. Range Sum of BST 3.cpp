// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return dfs(root, low, high);
    }

    int dfs(TreeNode *root, int low, int high)
    {
        int result = 0;

        if (root == nullptr)
            return 0;

        if (root->val >= low && root->val <= high)
            result += root->val;

        return result + dfs(root->left, low, high) + dfs(root->right, low, high);
    }
};