// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int requiredTreeNode;
    int maxDepth = 0;

public:
    int findBottomLeftValue(TreeNode *root)
    {
        requiredTreeNode = root->val;
        DFS(root, 0);
        return requiredTreeNode;
    }

    void DFS(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return;

        if (depth > maxDepth)
        {
            maxDepth = depth;
            requiredTreeNode = root->val;
        }
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }
};