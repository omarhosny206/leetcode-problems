// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root)
    {
        return dfs(root, root);
    }

    bool dfs(TreeNode *firstRoot, TreeNode *secondRoot)
    {
        if (firstRoot == nullptr && secondRoot == nullptr)
            return true;

        if (firstRoot == nullptr || secondRoot == nullptr)
            return false;

        if (firstRoot->val != secondRoot->val)
            return false;

        bool left = dfs(firstRoot->left, secondRoot->right);
        bool right = dfs(firstRoot->right, secondRoot->left);
        return left && right;
    }
};