// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int result = 0;

public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *root, int currentSum)
    {
        if (root == nullptr)
            return;

        currentSum = (currentSum * 10) + root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            result += currentSum;
            return;
        }

        dfs(root->left, currentSum);
        dfs(root->right, currentSum);
    }
};