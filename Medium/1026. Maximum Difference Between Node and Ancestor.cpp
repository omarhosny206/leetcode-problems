// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return DFS(root, root->val, root->val);
    }

    int DFS(TreeNode *root, int currentMax, int currentMin)
    {
        if (root == nullptr)
            return currentMax - currentMin;

        currentMax = max(currentMax, root->val);
        currentMin = min(currentMin, root->val);

        int left = DFS(root->left, currentMax, currentMin);
        int right = DFS(root->right, currentMax, currentMin);

        return max(left, right);
    }
};